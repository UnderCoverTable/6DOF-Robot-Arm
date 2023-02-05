// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Servo.h>



Adafruit_MPU6050 mpu;

float AccX,AccY,AccZ,GyroX,GyroY,GyroZ,Temp;

Servo servos[6];
const byte servoPins[6] =  {3,5,6,9,10,11};
float servosCurAngle[6] = {90,90,90,90,90,90};
float servosAngleIncrement[6] = {1,1,1,1,1,1};



void setup(void) {

  for(int i = 0; i < 5; i++){
    servos[i].attach(servoPins[i]);
    servos[i].write(servosCurAngle[i]);
    delay(500);
  }

  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_4_G); // 2 4 8 16 -> Smaller more sensitive

  mpu.setGyroRange(MPU6050_RANGE_500_DEG); // 250 500 1000 2000 -> Smaller more sensitive
 
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ); // 246(=0) 184 94 44 21 10 5 -> Remove high frequency data (low-pass filter’s cutoff frequency)

  delay(100);
}

void loop() {

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  AccX = a.acceleration.x;

  if(servosCurAngle[0] != 170 && AccX > 1){
    servosAngleIncrement[0] = AccX;
    servosCurAngle[0] += servosAngleIncrement[0];

  }
  else if(servosCurAngle[0] != 10 && AccX < -1){
    servosAngleIncrement[0] = AccX;
    servosCurAngle[0] += servosAngleIncrement[0];
  }
  Serial.println(AccX);
  servos[0].write(servosCurAngle[0]);
  delay(50);
  
  // AccY = a.acceleration.y;
  // AccZ = a.acceleration.z;

  // GyroX = g.gyro.x;
  // GyroY = g.gyro.y;
  // GyroZ = g.gyro.z;

  // Temp = temp.temperature;

  	/* Print out the values */
  // Serial.print("AccelX:");
  // Serial.println(a.acceleration.x);
  // Serial.print(",");
  // Serial.print("AccelY:");
  // Serial.print(a.acceleration.y);
  // Serial.print(",");
  // Serial.print("AccelZ:");
  // Serial.print(a.acceleration.z);
  // Serial.print(", ");
  // Serial.print("GyroX:");
  // Serial.print(g.gyro.x);
  // Serial.print(",");
  // Serial.print("GyroY:");
  // Serial.print(g.gyro.y);
  // Serial.print(",");
  // Serial.print("GyroZ:");
  // Serial.print(g.gyro.z);
  // Serial.println("");

}