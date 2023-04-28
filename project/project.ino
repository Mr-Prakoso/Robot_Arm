#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>
#include <Servo.h>

Servo servoA, servoB, servoC, servoD;

#include <RemoteXY.h>

#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600

#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 28 bytes
  { 255,4,0,0,0,35,0,16,31,0,4,0,57,9,6,47,2,26,4,0,
  71,9,6,47,2,26,4,0,85,9,6,47,2,26,4,128,9,39,38,5,
  2,26 };
  
struct {
  int8_t B; // =0..100 slider position 
  int8_t C; // =0..100 slider position 
  int8_t D; // =0..100 slider position 
  int8_t A; // =0..100 slider position 

  uint8_t connect_flag;  // =1 if wire connected, else =0 
} RemoteXY;
#pragma pack(pop)

void setup() {
  RemoteXY_Init (); 
  Serial.begin(9600);

  servoA.attach(5);
  servoB.attach(6);
  servoC.attach(9);
  servoD.attach(10);
}

void loop() { 
  RemoteXY_Handler ();

  servoA.write(map(RemoteXY.A, 100, 0, 0, 180));
  servoB.write(map(RemoteXY.B, 100, 0, 30, 180));
  servoC.write(map(RemoteXY.C, 0, 100, 180, 50));
  servoD.write(map(RemoteXY.D, 0, 100, 10, 150));
}