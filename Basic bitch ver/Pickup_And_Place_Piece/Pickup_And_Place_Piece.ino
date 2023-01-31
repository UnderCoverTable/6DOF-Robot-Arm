#include <Servo.h>

// Servo servo1,servo2,servo3,servo4,servo5,servo6;

Servo servos[6];
const byte servoPins[6] =  {3,5,6,9,10,11};







void setup() {
  Serial.begin(9600);

 
  go_and_grab();

  place_and_drop();

  // delay(1000);

  // servos[0].write(140);

  // delay(2000);

  // servos[5].write(30);


  




}



void loop() {


}

void place_and_drop(){
    // for(int i = 0; i < 6; i++){

      delay(1500);
    // if(i == 2){
      // servos[0].attach(servoPins[0]);
      servos[0].write(90);
      delay(100);
            servos[0].write(85);
      delay(100);
            servos[0].write(80);
      delay(100);
            servos[0].write(75);
      delay(100);
                  servos[0].write(70);
      delay(100);
                  servos[0].write(65);
      delay(100);
                  servos[0].write(60);
      delay(100);      
    

    // }



  // }

  delay(2000);

  servos[5].write(30);

  delay(2000);

  servos[0].write(100);

}

void go_and_grab(){
   for(int i = 0; i < 6; i++){
    if(i == 0){
      servos[i].attach(servoPins[i]);
      servos[i].write(100);
      delay(500);
    }

        if(i == 1){
      servos[i].attach(servoPins[i]);
      servos[i].write(120);
      delay(500);
    }

        if(i == 2){
      servos[i].attach(servoPins[i]);
      servos[i].write(140);
      delay(500);
    }

        if(i == 3){
      servos[i].attach(servoPins[i]);
      servos[i].write(100);
      delay(500);
    }

        if(i == 4){
      servos[i].attach(servoPins[i]);
      servos[i].write(60);
      delay(500);
    }

        if(i == 5){
      servos[i].attach(servoPins[i]);
      servos[i].write(30);
      delay(500);
    }

  }


  delay(3000);
  servos[5].write(100);

}
