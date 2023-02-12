#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();   // Initiates library.

#define SERVOMIN  10  // Minimum pulse length count out of 4096.
#define SERVOMAX  380 // Maximum pulse length count out of 4096.

int servoNo = 0; // Defines a counter for servos.


void setup() 
{
  Serial.begin(9600);       // Starts serial connecton at 9600 baud rate.
  
  pwm.begin();         // Sends PWM signals.
  pwm.setPWMFreq(60);  // Makes servos run at 60 Hz rate.
  delay(20);
}


void loop() 
{   
  
    pwm.setPWM(servoNo, 0, 100);                            // to maximum pulse length then to minimum pulse length.
    pwm.setPWM(servoNo, 7, 100);                            // to maximum pulse length then to minimum pulse length.
    
  


} 
