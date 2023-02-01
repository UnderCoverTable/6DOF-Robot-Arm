
/* Include the HCPCA9685 library */
#include "HCPCA9685.h"

/* I2C slave address for the device/module. For the HCMODU0097 the default I2C address
   is 0x40 */
#define  I2CAdd 0x40


/* Create an instance of the library */
HCPCA9685 HCPCA9685(I2CAdd);

int p1 = A0;
int p2 = A1;
int p3 = A2;

int val1 = 0;
int val2 = 0;
int val3 = 0;





void setup() 
{
  /* Initialise the library and set it to 'servo mode' */ 
  HCPCA9685.Init(SERVO_MODE);

  /* Wake the device up */
  HCPCA9685.Sleep(false);
}


void loop() 
{

    val1 = analogRead(p1);
    val1 = map(val1, 0, 1023, 10, 380); 
    HCPCA9685.Servo(1, val1);

    
    val2 = analogRead(p2);
    val2 = map(val2, 0, 1023, 10, 380); 
    HCPCA9685.Servo(2, val2);

    
    val3 = analogRead(p3);
    val3 = map(val3, 0, 1023, 10, 380); 
    HCPCA9685.Servo(3, val3);
    
  
}
