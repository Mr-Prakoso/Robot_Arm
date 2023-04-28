#include <Servo.h>

Servo servoA, servoB, servoC, servoD;

void setup() {
  Serial.begin(9600);

  servoA.attach(5);
  servoB.attach(6);
  servoC.attach(9);
  servoD.attach(10);
}

void loop() {
  if(Serial.available()){
    char x = Serial.read();
    String i = Serial.readString();
    if(x == 'a'){servoA.write(i.toInt());}
    else if(x == 'b'){servoB.write(i.toInt());}
    else if(x == 'c'){servoC.write(i.toInt());}
    else if(x == 'd'){servoD.write(i.toInt());}
  }
}