void parseIncomingString(String str)
{
  String str0 = "mHoursOn=";
  String str1 = "&mMinutesOn=";
  mHoursOn = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&mHoursOff=";
  mMinutesOn = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&mMinutesOff=";
  mHoursOff = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&tHoursOn=";
  mMinutesOff = extractInteger(str, str0, str1);
  
  str0 = str1;
  str1 = "&tMinutesOn=";
  tHoursOn = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&tHoursOff=";
  tMinutesOn = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&tMinutesOff=";
  tHoursOff = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&wHoursOn=";
  tMinutesOff = extractInteger(str, str0, str1);
  
  str0 = str1;
  str1 = "&wMinutesOn=";
  wHoursOn = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&wHoursOff=";
  wMinutesOn = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&wMinutesOff=";
  wHoursOff = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&rHoursOn=";
  wMinutesOff = extractInteger(str, str0, str1);
  
  str0 = str1;
  str1 = "&rMinutesOn=";
  rHoursOn = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&rHoursOff=";
  rMinutesOn = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&rMinutesOff=";
  rHoursOff = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&fHoursOn=";
  rMinutesOff = extractInteger(str, str0, str1);
  
  str0 = str1;
  str1 = "&fMinutesOn=";
  fHoursOn = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&fHoursOff=";
  fMinutesOn = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&fMinutesOff=";
  fHoursOff = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&sHoursOn=";
  fMinutesOff = extractInteger(str, str0, str1);
  
  str0 = str1;
  str1 = "&sMinutesOn=";
  sHoursOn = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&sHoursOff=";
  sMinutesOn = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&sMinutesOff=";
  sHoursOff = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&nHoursOn=";
  sMinutesOff = extractInteger(str, str0, str1);
  
  str0 = str1;
  str1 = "&nMinutesOn=";
  nHoursOn = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&nHoursOff=";
  nMinutesOn = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = "&nMinutesOff=";
  nHoursOff = extractInteger(str, str0, str1);
  str0 = str1;
  str1 = " HTTP/1.1";
  nMinutesOff = extractInteger(str, str0, str1);
}

int extractInteger(String str, String sub0, String sub1)
{
  int index0 = 0;
  int index1 = 0;
  index0 = str.indexOf(sub0) + sub0.length();
  index1 = str.indexOf(sub1);
  return str.substring(index0, index1).toInt();
}
