// This code was lifted more or less whole-hog from the SparkFun Big GPS Clock
//  project. I wrote that too.

bool dstCheck()
{
  //Serial.println("DST Check");
  // As of 2007, most of the US observes DST between the 2nd Sunday morning in
  //  March and the 1st Sunday morning in November. DST in the US changes by
  //  time zone, so at 2am local time on the 2nd Sunday in March, we increase
  //  the offset from UTC by one hour.
  
  // We can bail out if month is < 3 or > 11.
  if ( (month() < 3) || (month() > 11) )
  {
    return false;
  }

  // We can also bail out if month is > 3 and < 11.
  if ( (month() > 3) && (month() < 11) )
  {
    return true;
  }
  
  // Okay, edge cases, March and November. We can do a couple more low-math
  //  checks to quickly decide whether the date is a possible one.
  // For November, the date of the first Sunday *must* be less than 8, so if
  //  the date is greater than 8, we can return false.
  if (month() == 11)
  {
    if (day() > 7)
    {
      return false;
    }
    // Otherwise, we need to figure out whether we've seen the first Sunday
    //  yet.
    TimeElements firstOfNovTE;
    firstOfNovTE.Day = 1;
    firstOfNovTE.Month = 3;
    firstOfNovTE.Year = year();
    firstOfNovTE.Hour = 0;
    firstOfNovTE.Minute = 0;
    firstOfNovTE.Second = 0;
    time_t firstOfNov = makeTime(firstOfNovTE);
    int8_t firstDayOfNov = weekday(firstOfNov);
    int8_t firstSundayOfNov = (9 - firstDayOfNov) % 7;
    // If we *haven't* seen the first Sunday yet, we are in DST still.
    if (day() < firstSundayOfNov)
    {
      return true;
    }

    // If it's *after* the first Sunday, we aren't in DST anymore.
    if (day() > firstSundayOfNov)
    {
      return false;
    }
    
    // If we're here, it's the first Sunday of November right now, and we only
    //  need to know if the current hour is < 2; at 0200 MST, DST ends.
    if (hour() < 2)
    {
      return true;
    }
    return false;
  }

  // For March, dates less than 8, or greater than 13 are automatically out.
  if (month() == 3)
  {
    if (day() < 8)
    {
      return false;
    }
    if (day() > 13)
    {
      return true;
    }

    // Otherwise, we need to figure out whether we've see the second Sunday
    //  yet. 
    // TimeElements is a struct, but we have to initialize it in the long-form, due
    //  to limitations of the compiler used by the Arduino IDE.
    TimeElements firstOfMarTE;
    firstOfMarTE.Day = 1;
    firstOfMarTE.Month = 3;
    firstOfMarTE.Year = year();
    firstOfMarTE.Hour = 0;
    firstOfMarTE.Minute = 0;
    firstOfMarTE.Second = 0;
    time_t firstOfMar = makeTime(firstOfMarTE);
    int8_t firstDayOfMar = weekday(firstOfMar);
    int8_t secondSundayOfMar = ((9 - firstDayOfMar) % 7) + 7;

    // If we *haven't* seen the second Sunday yet, we aren't in DST yet.
    if (day() < secondSundayOfMar)
    {
      return false;
    }

    // If it's *after* the second Sunday, we are in DST now.
    if (day() > secondSundayOfMar)
    {
      return true;
    }
    
    // If we're here, it's the second Sunday of November right now, and we only
    //  need to know if the current hour is < 2; at 0200 MST, DST starts.
    if (hour() < 2)
    {
      return false;
    }
    return true;
  }
  return false; // We *should* never get here, but we need to return something
                //  or chaos ensues.
}
