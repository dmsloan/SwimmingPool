void checkAlarm()
{
  int dow = weekday();
  int secsOfDay = hour()*3600 + minute()*60 + second();
  int timeOn, timeOff;
  switch(dow)
  {
    case 1: // Sundays
      timeOn = nHoursOn*3600 + nMinutesOn*60;
      timeOff = nHoursOff*3600 + nMinutesOff*60;
      break;
    case 2: // Mondays
      timeOn = mHoursOn*3600 + mMinutesOn*60;
      timeOff = mHoursOff*3600 + mMinutesOff*60;
      break;
    case 3: // Tuesdays
      timeOn = tHoursOn*3600 + tMinutesOn*60;
      timeOff = tHoursOff*3600 + tMinutesOff*60;
      break;
    case 4: // Wednesdays
      timeOn = wHoursOn*3600 + wMinutesOn*60;
      timeOff = wHoursOff*3600 + wMinutesOff*60;
      break;
    case 5: // Thursdays
      timeOn = rHoursOn*3600 + rMinutesOn*60;
      timeOff = rHoursOff*3600 + rMinutesOff*60;
      break;
    case 6: // Fridays
      timeOn = fHoursOn*3600 + fMinutesOn*60;
      timeOff = fHoursOff*3600 + fMinutesOff*60;
      break;
    case 7: // Saturdays
      timeOn = sHoursOn*3600 + sMinutesOn*60;
      timeOff = sHoursOff*3600 + sMinutesOff*60;
      break;
  }
  if (timeOn > timeOff)
  {
    if (secsOfDay > timeOn) turnOn();
    else if (secsOfDay > timeOff) turnOff();
  }
  else
  {
    if (secsOfDay > timeOff) turnOff();
    else if (secsOfDay > timeOn) turnOn();
  }
}
