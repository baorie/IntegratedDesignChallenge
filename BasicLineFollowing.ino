#include <Servo.h>

Servo servoL;
Servo servoR;

long sensors_average;
int sensors_sum;
int position;
long sensors[] = {0, 0, 0}; // Array used to store 5 readings for 5 sensors

const int lef = 0;
const int mid = 0;
const int rt = 0;

void setup(){
  Serial.begin(9600);
  servoL.attach(13);  // Set up for Arduino Serial Monitor at 9600 baud
  servoR.attach(12);  // Attach (programmatically connect) servos to pins on Arduino
}

void loop(){
  //Find out what pins they're in!!
  sensors_average = 0;
  sensors_sum = 0;

  for(int i = 0; i < 3; i++){
    sensors[i] = digitalRead(i); //we should put the sensors in those pins
    sensors_average += sensors[i] * i * 1000; // Calculating the weighted mean
    sensors_sum += int(sensors[i]);
  }

  position = int(sensors_average/sensors_sum);
  Serial.print(sensors_average);
  Serial.print(' ');
  Serial.print(sensors_sum);
  Serial.print(' ');
  Serial.print(position);
  Serial.println():
  delay(2000);

  /*
  int leftPin = digitalRead(lef);
  int middlePin = digitalRead(mid);
  int rightPin = digitalRead(rt);

  Serial.print(leftPin);
  Serial.print(' ');
  Serial.print(middlePin);
  Serial.print(' ');
  Serial.print(rightPin);
  Serial.println(' ')l
  delay(1500); //Set the number to change frequency of readings
  */



}
