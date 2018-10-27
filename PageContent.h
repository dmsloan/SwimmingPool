String pageContentHead = 
"HTTP/1.1 200 OK\r\n\
Content-type:text/html\r\n\
\r\n\
<!DOCTYPE html> <html>\
<style>\
input[type=text] {\
  width: 20px;\
}\
form {\
  font-family: monospace;\
}\
table, th, td {\
  text-align: left;\
  border: 5px;\
}\
</style>\
<head>\
<title>Swimming Pool</title>\
</head>\
<body>\
<h3>Pump motor start/stop</h3>";

char pageContentBody[] =
"<form id=\"timeForm\">\
<table>\
<tr>\
<th>Day</th><th>On Time</th><th>Off Time</th>\
</tr>\
<tr>\
<td>Monday</td>\
<td><input type=\"text\" name=\"mHoursOn\" value=\"%d\">:<input type=\"text\" name=\"mMinutesOn\" value=\"%02d\"></td>\
<td><input type=\"text\" name=\"mHoursOff\" value=\"%d\">:<input type=\"text\" name=\"mMinutesOff\" value=\"%02d\"></td>\
</tr>\
<tr>\
<td>Tuesday</td>\
<td><input type=\"text\" name=\"tHoursOn\" value=\"%d\">:<input type=\"text\" name=\"tMinutesOn\" value=\"%02d\"></td>\
<td><input type=\"text\" name=\"tHoursOff\" value=\"%d\">:<input type=\"text\" name=\"tMinutesOff\" value=\"%02d\"></td>\
</tr>\
<tr>\
<td>Wednesday</td>\
<td><input type=\"text\" name=\"wHoursOn\" value=\"%d\">:<input type=\"text\" name=\"wMinutesOn\" value=\"%02d\"></td>\
<td><input type=\"text\" name=\"wHoursOff\" value=\"%d\">:<input type=\"text\" name=\"wMinutesOff\" value=\"%02d\"></td>\
</tr>\
<tr>\
<td>Thursday</td>\
<td><input type=\"text\" name=\"rHoursOn\" value=\"%d\">:<input type=\"text\" name=\"rMinutesOn\" value=\"%02d\"></td>\
<td><input type=\"text\" name=\"rHoursOff\" value=\"%d\">:<input type=\"text\" name=\"rMinutesOff\" value=\"%02d\"></td>\
</tr>\
<tr>\
<td>Friday</td>\
<td><input type=\"text\" name=\"fHoursOn\" value=\"%d\">:<input type=\"text\" name=\"fMinutesOn\" value=\"%02d\"></td>\
<td><input type=\"text\" name=\"fHoursOff\" value=\"%d\">:<input type=\"text\" name=\"fMinutesOff\" value=\"%02d\"></td>\
</tr>\
<tr>\
<td>Saturday</td>\
<td><input type=\"text\" name=\"sHoursOn\" value=\"%d\">:<input type=\"text\" name=\"sMinutesOn\" value=\"%02d\"></td>\
<td><input type=\"text\" name=\"sHoursOff\" value=\"%d\">:<input type=\"text\" name=\"sMinutesOff\" value=\"%02d\"></td>\
</tr>\
<tr>\
<td>Sunday</td>\
<td><input type=\"text\" name=\"nHoursOn\" value=\"%d\">:<input type=\"text\" name=\"nMinutesOn\" value=\"%02d\"></td>\
<td><input type=\"text\" name=\"nHoursOff\" value=\"%d\">:<input type=\"text\" name=\"nMinutesOff\" value=\"%02d\"></td>\
</tr>\
</table>\
<button type=\"button\" onClick=\"submitTimes()\">Submit</button><br>\
<a href=\"/reset\">Reset times</a><br>\
</form>\
<p id=\"responseText\"></p>\
<script>\
function submitTimes() {\
  var hrs, mins, text;\
  \
  hrs = document.forms[\"timeForm\"][\"mHoursOn\"].value;\
  mins = document.forms[\"timeForm\"][\"mMinutesOn\"].value;\
  if (!validateHrs(hrs)) return;\
  if (!validateMins(mins)) return;\
  hrs = document.forms[\"timeForm\"][\"mHoursOff\"].value;\
  mins = document.forms[\"timeForm\"][\"mMinutesOff\"].value;\
  if (!validateHrs(hrs)) return;\
  if (!validateMins(mins)) return;\
  \
  hrs = document.forms[\"timeForm\"][\"tHoursOn\"].value;\
  mins = document.forms[\"timeForm\"][\"tMinutesOn\"].value;\
  if (!validateHrs(hrs)) return;\
  if (!validateMins(mins)) return;\
  hrs = document.forms[\"timeForm\"][\"tHoursOff\"].value;\
  mins = document.forms[\"timeForm\"][\"tMinutesOff\"].value;\
  if (!validateHrs(hrs)) return;\
  if (!validateMins(mins)) return;\
  \
  hrs = document.forms[\"timeForm\"][\"wHoursOn\"].value;\
  mins = document.forms[\"timeForm\"][\"wMinutesOn\"].value;\
  if (!validateHrs(hrs)) return;\
  if (!validateMins(mins)) return;\
  hrs = document.forms[\"timeForm\"][\"wHoursOff\"].value;\
  mins = document.forms[\"timeForm\"][\"wMinutesOff\"].value;\
  if (!validateHrs(hrs)) return;\
  if (!validateMins(mins)) return;\
  \
  hrs = document.forms[\"timeForm\"][\"rHoursOn\"].value;\
  mins = document.forms[\"timeForm\"][\"rMinutesOn\"].value;\
  if (!validateHrs(hrs)) return;\
  if (!validateMins(mins)) return;\
  hrs = document.forms[\"timeForm\"][\"rHoursOff\"].value;\
  mins = document.forms[\"timeForm\"][\"rMinutesOff\"].value;\
  if (!validateHrs(hrs)) return;\
  if (!validateMins(mins)) return;\
  \
  hrs = document.forms[\"timeForm\"][\"fHoursOn\"].value;\
  mins = document.forms[\"timeForm\"][\"fMinutesOn\"].value;\
  if (!validateHrs(hrs)) return;\
  if (!validateMins(mins)) return;\
  hrs = document.forms[\"timeForm\"][\"fHoursOff\"].value;\
  mins = document.forms[\"timeForm\"][\"fMinutesOff\"].value;\
  if (!validateHrs(hrs)) return;\
  if (!validateMins(mins)) return;\
  \
  hrs = document.forms[\"timeForm\"][\"sHoursOn\"].value;\
  mins = document.forms[\"timeForm\"][\"sMinutesOn\"].value;\
  if (!validateHrs(hrs)) return;\
  if (!validateMins(mins)) return;\
  hrs = document.forms[\"timeForm\"][\"sHoursOff\"].value;\
  mins = document.forms[\"timeForm\"][\"sMinutesOff\"].value;\
  if (!validateHrs(hrs)) return;\
  if (!validateMins(mins)) return;\
  \
  hrs = document.forms[\"timeForm\"][\"nHoursOn\"].value;\
  mins = document.forms[\"timeForm\"][\"nMinutesOn\"].value;\
  if (!validateHrs(hrs)) return;\
  if (!validateMins(mins)) return;\
  hrs = document.forms[\"timeForm\"][\"nHoursOff\"].value;\
  mins = document.forms[\"timeForm\"][\"nMinutesOff\"].value;\
  if (!validateHrs(hrs)) return;\
  if (!validateMins(mins)) return;\
  \
  text = \"Times valid!\";\
  document.getElementById(\"timeForm\").submit();\
  document.getElementById(\"responseText\").innerHTML = text;\
}\
\
function validateMins(mins) {\
  if (isNaN(mins) || mins < 0 || mins > 59) {\
    return false;\
  }\
  return true;\
}\
\
function validateHrs(hrs) {\
  if (isNaN(hrs) || hrs < 0 || hrs > 23) {\
    return false;\
  }\
  return true;\
}\
\
</script>";

String pageContentFoot =
"</body>"
"</html>\r\n";
