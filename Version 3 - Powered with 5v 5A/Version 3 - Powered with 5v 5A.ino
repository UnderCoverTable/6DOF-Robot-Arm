#include <Servo.h>

// Servo servo1,servo2,servo3,servo4,servo5,servo6;

Servo servos[6];
const byte servoPins[6] =  {3,5,6,9,10,11};

int b8[6] = {90,170,165,90,170,20};
int g2[6] = {160,170,155,80,170,20};
int c3[6] = {130,170,165,100,170,20};





void setup() {
  Serial.begin(9600);

  arm_init(1);
  delay(2000);

  go_and_grab(c3);
  delay(1000);

  arm_init(2);
  delay(1000);

  place_and_drop(b8);

  delay(1000);
  
  arm_init(2);
  delay(2000);

  go_and_grab(b8);
  delay(1000);

  arm_init(2);
  delay(1000);

  place_and_drop(g2);

  delay(1000);
  arm_init(2);

}



void loop() {


}

void place_and_drop(int *arr){

  
    // SmoothWrite(arr[0],0);
    servos[0].write(arr[0]);
    delay(500);
    
    servos[4].write(arr[4]);
    delay(500);

    SmoothWrite(arr[3],3);
    delay(500);
  
    SmoothWrite(arr[2],2);

    delay(500);

    SmoothWrite(arr[1],1);
    delay(500);

    delay(2000);

    servos[5].write(arr[5]);
    delay(500);
    // servos[5].write(160);
    // delay(1000);

}

void go_and_grab(int *arr){


    servos[0].write(arr[0]);
    delay(500);


    servos[5].write(arr[5]);
    delay(500);
    
    servos[4].write(arr[4]);
    delay(500);

    
    SmoothWrite(arr[3],3);
    delay(500);
  
    SmoothWrite(arr[2],2);

    delay(500);

    SmoothWrite(arr[1],1);
    delay(500);

    delay(2000);

    servos[5].write(160);
    delay(1000);

}

void SmoothWrite(int EndAngle,int ServoNumber){

  int startAngle = servos[ServoNumber].read();
  int inc_or_dic;



  if(EndAngle > startAngle){
    inc_or_dic = 0;
  } 
  
  else{
    inc_or_dic = 1;
  }


  if(inc_or_dic == 0){
    for(int ang = startAngle -5; ang != EndAngle; ang += 5){
      servos[ServoNumber].write(ang);
      delay(125);
    }
  }
  else{
    for(int ang = startAngle -5; ang != EndAngle; ang -= 5){
      servos[ServoNumber].write(ang);
      delay(125);

    }
  }

}

void arm_init(int mode){

  if(mode == 1){
    for(int i = 5; i!=-1; i--){
      servos[i].attach(servoPins[i]);
      servos[i].write(105);
      delay(125);
    } 
  }
  else if(mode == 2){
    for(int i = 1; i!=3; i++){
      servos[i].write(105);
      // SmoothWrite(105,i);
      delay(125);
    }
  }


}
