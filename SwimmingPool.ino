/****************************************************************************
 * This project was derived from the following:
 * TeleSitter.ino
 * Mike Hord @ SparkFun Electronics
 *
 * Modified by Derek Sloan
 * November 2018
 * 
 * Establishes the various header includes, global variables, etc that the
 * overall program requires. Implements setup(), loop() and a few other
 * utility functions.
 * 
 * Resources:
 * ESP32 Arduino support
 * Arduino Time library
 *  
 * Development environment specifics:
 * Arduino 1.8.5
 * ESP32
 * 
 * This code is beerware; if you see me (or any other SparkFun employee) at the
 * local, and you've found our code helpful, please buy us a round!
 * ****************************************************************************/

#include <WiFi.h>
#include "PageContent.h" //the html that is served to the cliet is in this file
#include "time.h"        //native ESP32 time library
#include <Preferences.h> //library that stores to ESP32 non-volatile memory
#include "TimeLib.h"     //Arduino time library
//#include <Wire.h>      //This library allows you to communicate with I2C devices
#include "WiFiInfo.h"    //stroes the SSID and PASSWORD in seperate file so it will not be uploaded to github

const char* ssid      = SSID;     //this value is retreved from WiFiInfo.h
const char* password  = PASSWORD; //this value is retreved from WiFiInfo.h

const char* ntpServer = "pool.ntp.org";  // coincidentally called pool even though it has nothing to do with the SwimmingPool sketch

int mHoursOn;
int mMinutesOn;
int mHoursOff;
int mMinutesOff;

int tHoursOn;
int tMinutesOn;
int tHoursOff;
int tMinutesOff;

int wHoursOn;
int wMinutesOn;
int wHoursOff;
int wMinutesOff;

int rHoursOn;
int rMinutesOn;
int rHoursOff;
int rMinutesOff;

int fHoursOn;
int fMinutesOn;
int fHoursOff;
int fMinutesOff;

int sHoursOn;
int sMinutesOn;
int sHoursOff;
int sMinutesOff;

int nHoursOn;
int nMinutesOn;
int nHoursOff;
int nMinutesOff;

#define pumpMotor 16      // pump motor
#define sweeperMotor 17   // sweeper motor
#define heater 18         // heater
#define inletValve 19     //inlet valve
#define dischargeValve 21 // discharge valve

WiFiServer server(80);
Preferences alarmTimes; // Oddly, the non-volatile memory library for ESP32 is called "Preferences". ???

// Runs once.
void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);  // Also has a blue LED on the ESP32 Thing
  pinMode(pumpMotor, OUTPUT);
  pinMode(sweeperMotor, OUTPUT);
  pinMode(heater, OUTPUT);
  pinMode(inletValve, OUTPUT);
  pinMode(dischargeValve, OUTPUT);

  Serial.println("This sketch is called SwimmingPool.ino");

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  int wifiCounter = 0;
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
    if (++wifiCounter > 30) ESP.restart();
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Initialize the Non Volitle Memory storage handler and fetch the cached
  //  alarm time information. Reigion is called SwimmingPool and the second parameter is always false
  alarmTimes.begin("SwimmingPool", false);
  getAlarmTimes();  // defined in NVM.ino

  // Enable the server functionality.
  server.begin();

  // We use two different timekeeping services, the ESP32 built-in
  //  and the one from the Arduino TimeLib. Why? Because the ESP32
  //  based one gets its time from an NTP server and it's unclear
  //  which functions it uses that ping the NTP server, so we want
  //  to avoid excessive NTP checks.

  // Preeeetty sure configTime() pings the NTP server. Parameters
  //  are GMT offset in seconds, DST offset in seconds, and NTP
  //  server address.
  configTime((-7*3600), 0, ntpServer);
  // A tm struct holds time info. It can be current local time, as
  //  here, or an arbitrary time, as used elsewhere.
  struct tm timeinfo;
  // Unclear as to whether getLocalTime() populates the tm struct
  //  solely from the local clock or from the NTP server. Thus, we
  //  avoid calling it too often by setting the Arduino timekeeping
  //  with it at boot time, then using the Arduino timekeeping for
  //  most of our timekeeping duties.
  getLocalTime(&timeinfo);
  // Set the Arduino library timekeeping to currrent time derived
  //  from the NTP server. We have to add 1 to the month as returned by
  //  the ESP32 module, as Arduino numbers months starting from 1 and ESP
  //  numbers starting from 0. Also, add 1900 to the year, as Arduino stores
  //  the full year number and ESP stores it as an offset from year 1900.
  setTime(timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec, 
          timeinfo.tm_mday, timeinfo.tm_mon+1, timeinfo.tm_year + 1900);
  // Check to see if DST is in effect. This function relies upon
  //  having the Arduino timekeeping set. We'll repeat this check
  //  once a day at 3am and reset the Arduino clock accordingly.
  if (dstCheck()) configTime((-7*3600), 3600, ntpServer);
  else configTime((-7*3600), 0, ntpServer);
  // Fetch the current time into timeInfo again. This is now DST
  //  correct local time.
  getLocalTime(&timeinfo);
  // Set the Arduino clock to DST correct local time.
  setTime(timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec, 
          timeinfo.tm_mday, timeinfo.tm_mon+1, timeinfo.tm_year + 1900);
}

// Main operation of the program. Repeat as fast as possible.
void loop(){

  // Health check. If we've lost our wifi connection, restart
  //  the ESP to (hopefully) reconnect without user noticing.
  if (WiFi.status() != WL_CONNECTED) 
  {
    Serial.println("WiFi dropped; rebooting");
    delay(100);
    ESP.restart();
  }

  // Check to see what our current alarm status is, i.e., should
  //  our output be on or off?
  checkAlarm();

  // At 3 a.m. daily run our clock setting routine. Again, this
  //  pings the NTP server we set up above, so we don't want to
  //  do it too often lest we anger the NTP gods.
  if (hour() == 3 && minute() == 0 && second() == 0)
  {
    struct tm timeinfo;
    getLocalTime(&timeinfo);
    setTime(timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec, 
            timeinfo.tm_mday, timeinfo.tm_mon + 1, timeinfo.tm_year + 1900);
    // Check to see if DST is in effect. 
    if (dstCheck()) configTime((-7*3600), 3600, ntpServer);
    else configTime((-7*3600), 0, ntpServer);
    getLocalTime(&timeinfo);
    setTime(timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec, 
            timeinfo.tm_mday, timeinfo.tm_mon + 1, timeinfo.tm_year + 1900);
  }

  // Enter the client/server handling section of the code. This part was taken
  //  mostly whole-hog from an example that ships with the ESP32 Arduino
  //  support package.
  WiFiClient client = server.available();   // listen for incoming clients
  if (client) {                             // if you get a client,
    Serial.println("New Client.");          // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected())              // loop while the client's connected
    {            
      if (client.available())               // if there's bytes to read from the client,
      {             
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n')                      // if the byte is a newline character
        {                    
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) 
          {
            // We've split up the repsonse into a few blocks, to make editing a
            //  bit easier.
            client.print(pageContentHead);  //pageContentHead and the like is defined in PageContent.h
            client.printf(pageContentBody, mHoursOn, mMinutesOn, mHoursOff, mMinutesOff,
                                           tHoursOn, tMinutesOn, tHoursOff, tMinutesOff,
                                           wHoursOn, wMinutesOn, wHoursOff, wMinutesOff,
                                           rHoursOn, rMinutesOn, rHoursOff, rMinutesOff,
                                           fHoursOn, fMinutesOn, fHoursOff, fMinutesOff,
                                           sHoursOn, sMinutesOn, sHoursOff, sMinutesOff,
                                           nHoursOn, nMinutesOn, nHoursOff, nMinutesOff);
            // Print out the current time and date. This is useful for debugging
            //  as it's the only way to check the internal server clock.
            client.printf("%d:%02d:%02d<br>", hour(), minute(), second());
            client.printf("%d/%d/%d %d<br>", day(), month(), year(), weekday());
            client.print(pageContentFoot);
            break;
          } 
          else                // if you got a newline, then clear currentLine:
          {    
            currentLine = "";
          }
        } 
        else if (c != '\r')   // if you got anything else but a carriage return character,
        {
          currentLine += c;      // add it to the end of the currentLine
        }

        // Handle the types of request that we expect to get

        // We can get a request to reset the alarm times
        if (currentLine.endsWith("GET /reset"))
        {
          resetAlarmTimes();
        }
        if (currentLine.endsWith("HTTP/1.1"))
        {
          if (currentLine.startsWith("GET /?"))
          {
            parseIncomingString(currentLine);
            storeAlarmTimes();
          }
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}

void turnOn()
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void turnOff()
{
  digitalWrite(LED_BUILTIN, LOW);
}
