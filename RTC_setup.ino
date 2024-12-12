#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

//Dont touch anything in here all it will do is set the RTC time to your computer's time.
//Check if it worked correctly (military time) by going to Tools --> Serial Monitor
void setup() {
  Serial.begin(9600);
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));



  Serial.println("RTC time set!");
}

void loop() {
  DateTime now = rtc.now();
  Serial.print("Time: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.println(now.second());
  delay(1000);
}
