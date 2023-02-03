#include <Servo.h>


Servo servo;
int servoPin = 10;
int servoRead = A0;
int servoVal;


void setup() {
  Serial.begin(9600);

  servo.attach(servoPin);

  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);



}

void loop() {

    servoVal = analogRead(servoRead);
    servoVal = map(servoVal, 0, 1023, 0, 180);
    servo.write(90);

    Serial.print("Servo ");
    Serial.print(": ");
    Serial.println(servoVal);
    


    delay(15);





    


}
