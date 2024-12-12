//Thanks for uisng a FurNow guide!

//These are libraries, don't remove them. Go to Sketch --> Include library --> Manage libraries and download the rtc library if it isn't already downloaded
#include <Wire.h>
#include <RTClib.h>
#include <Servo.h>

//telling the program "these are what I want to call my rtc and my servo motor"
RTC_DS3231 rtc;
Servo myServo;

//variables

int pos = 0;
int servoPin = 9;
int moveDuration = 1000;
unsigned long HOLD_OPEN_TIME = 1000; //this value will change how much time your cover will stay open/ how long the treats will fall

//Anything with "Serial" in front of it is for testing. Go to tools --> serial monitor to see the print statements to test for yourself.
//You can remove the serial prints after you're done testing
void setup() {
  if (!rtc.begin()) {

    while (1);
  }

  myServo.attach(servoPin);

}

void loop() {
  //Make sure to run the RTC adjustment code before this
  DateTime now = rtc.now();

  // Print current time for debugging

  // Check for specific times and trigger servo
  //You can change these numbers if you want. They're in military time ie. 13 = 1PM
  if ((now.hour() == 20 || now.hour() == 19 || now.hour() == 5) && now.minute() == 12 && now.second() == 0) {
    moveServo();
    delay(60000);  // Wait for 1 minute to prevent retriggering during the same minute
  }

  delay(1000);  // Check time every second
}

//controls how the servo moves. Change "pos" for the right angle for your build
void moveServo() {
  for (pos = 75; pos <= 180; pos += 1) {
    myServo.write(pos);
    delay(15);
  }
  delay(HOLD_OPEN_TIME);
  for (pos = 180; pos >= 75; pos -= 1) {
    myServo.write(pos);
    delay(15);
  }
}
