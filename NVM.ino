void resetAlarmTimes()
{
  mHoursOn = 8;
  mMinutesOn = 0;
  mHoursOff = 0;
  mMinutesOff = 0;
  tHoursOn = 8;
  tMinutesOn = 0;
  tHoursOff = 0;
  tMinutesOff = 0;
  wHoursOn = 8;
  wMinutesOn = 0;
  wHoursOff = 0;
  wMinutesOff = 0;
  rHoursOn = 8;
  rMinutesOn = 0;
  rHoursOff = 0;
  rMinutesOff = 0;
  fHoursOn = 8;
  fMinutesOn = 0;
  fHoursOff = 0;
  fMinutesOff = 0;
  sHoursOn = 8;
  sMinutesOn = 0;
  sHoursOff = 0;
  sMinutesOff = 0;
  nHoursOn = 8;
  nMinutesOn = 0;
  nHoursOff = 0;
  nMinutesOff = 0;
  storeAlarmTimes();
}

void storeAlarmTimes()
{
  alarmTimes.putInt("mHoursOn", mHoursOn);
  alarmTimes.putInt("mMinutesOn", mMinutesOn);
  alarmTimes.putInt("mHoursOff", mHoursOff);
  alarmTimes.putInt("mMinutesOff", mMinutesOff);
  
  alarmTimes.putInt("tHoursOn", tHoursOn);
  alarmTimes.putInt("tMinutesOn", tMinutesOn);
  alarmTimes.putInt("tHoursOff", tHoursOff);
  alarmTimes.putInt("tMinutesOff", tMinutesOff);
  
  alarmTimes.putInt("wHoursOn", wHoursOn);
  alarmTimes.putInt("wMinutesOn", wMinutesOn);
  alarmTimes.putInt("wHoursOff", wHoursOff);
  alarmTimes.putInt("wMinutesOff", wMinutesOff);
  
  alarmTimes.putInt("rHoursOn", rHoursOn);
  alarmTimes.putInt("rMinutesOn", rMinutesOn);
  alarmTimes.putInt("rHoursOff", rHoursOff);
  alarmTimes.putInt("rMinutesOff", rMinutesOff);
  
  alarmTimes.putInt("fHoursOn", fHoursOn);
  alarmTimes.putInt("fMinutesOn", fMinutesOn);
  alarmTimes.putInt("fHoursOff", fHoursOff);
  alarmTimes.putInt("fMinutesOff", fMinutesOff);
  
  alarmTimes.putInt("sHoursOn", sHoursOn);
  alarmTimes.putInt("sMinutesOn", sMinutesOn);
  alarmTimes.putInt("sHoursOff", sHoursOff);
  alarmTimes.putInt("sMinutesOff", sMinutesOff);
  
  alarmTimes.putInt("nHoursOn", nHoursOn);
  alarmTimes.putInt("nMinutesOn", nMinutesOn);
  alarmTimes.putInt("nHoursOff", nHoursOff);
  alarmTimes.putInt("nMinutesOff", nMinutesOff);
}

void getAlarmTimes()
{
  mHoursOn = alarmTimes.getInt("mHoursOn", 8);
  mMinutesOn = alarmTimes.getInt("mMinutesOn", 0);
  mHoursOff = alarmTimes.getInt("mHoursOff", 0);
  mMinutesOff = alarmTimes.getInt("mMinutesOff", 0);
  
  tHoursOn = alarmTimes.getInt("tHoursOn", 8);
  tMinutesOn = alarmTimes.getInt("tMinutesOn", 0);
  tHoursOff = alarmTimes.getInt("tHoursOff", 0);
  tMinutesOff = alarmTimes.getInt("tMinutesOff", 0);
  
  wHoursOn = alarmTimes.getInt("wHoursOn", 8);
  wMinutesOn = alarmTimes.getInt("wMinutesOn", 0);
  wHoursOff = alarmTimes.getInt("wHoursOff", 0);
  wMinutesOff = alarmTimes.getInt("wMinutesOff", 0);
  
  rHoursOn = alarmTimes.getInt("rHoursOn", 8);
  rMinutesOn = alarmTimes.getInt("rMinutesOn", 0);
  rHoursOff = alarmTimes.getInt("rHoursOff", 0);
  rMinutesOff = alarmTimes.getInt("rMinutesOff", 0);
  
  fHoursOn = alarmTimes.getInt("fHoursOn", 8);
  fMinutesOn = alarmTimes.getInt("fMinutesOn", 0);
  fHoursOff = alarmTimes.getInt("fHoursOff", 0);
  fMinutesOff = alarmTimes.getInt("fMinutesOff", 0);
  
  sHoursOn = alarmTimes.getInt("sHoursOn", 8);
  sMinutesOn = alarmTimes.getInt("sMinutesOn", 0);
  sHoursOff = alarmTimes.getInt("sHoursOff", 0);
  sMinutesOff = alarmTimes.getInt("sMinutesOff", 0);
  
  nHoursOn = alarmTimes.getInt("nHoursOn", 8);
  nMinutesOn = alarmTimes.getInt("nMinutesOn", 0);
  nHoursOff = alarmTimes.getInt("nHoursOff", 0);
  nMinutesOff = alarmTimes.getInt("nMinutesOff", 0);
}

