#include <Servo.h>                           // Use the Servo library (included with Arduino IDE)

Servo servoL;                                // Define the left and right servos
Servo servoR;

void setup()
{
  Serial.begin(9600);                        // Set up Arduino Serial Monitor at 9600 baud
  servoL.attach(13);                         // Attach (programmatically connect) servos to pins on Arduino
  servoR.attach(12);
}

void loop()
{

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
                        // Set level of Arduino pins D4-D7 to HIGH
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delayMicroseconds(230);                    // Short delay to allow capacitor charge in QTI module
                          // Set direction of pins D4-D7 as INPUT
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
                         // Set level of pins D4-D7 to LOW
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delayMicroseconds(230);                    // Short delay
                            // Get values of pins D0-D7
  int pin4 = digitalRead(4);
  int pin5 = digitalRead(5);
  int pin6 = digitalRead(6);
  int pin7 = digitalRead(7);

  Serial.print(pin4);                 // Display result of D4-D7 pins in Serial Monitor
  Serial.print(pin5);
  Serial.print(pin6);
  Serial.print(pin7);
  Serial.println(" ");

  int vL, vR;

  if (pin7 == 0 && pin6 == 1 && pin5 == 1 && pin4 == 0)
  {
    vL = 100;
      vR = 100;
  }

  if (pin7 == 1 && pin6 == 1 && pin5 == 1 && pin4 == 0)
  {
    vL = 100;
    vR = -100;
  }

  if (pin7 == 1 && pin6 == 1 && pin5 == 0 && pin4 == 0)
  {
    vL = 100;
    vR = -100;
  }

  if (pin7 == 1 && pin6 == 1 && pin5 == 0 && pin4 == 1)
  {
     vL = 100;
     vR = 50;
  }

  if (pin7 == 1 && pin6 == 0 && pin5 == 1 && pin4 == 1)
  {
    vL = 50;
    vR = 100;
  }

  if (pin7 == 0 && pin6 == 0 && pin5 == 1 && pin4 == 1)
  {
    vL = -100;
    vR = 100;
  }

  if (pin7 == 0 && pin6 == 1 && pin5 == 1 && pin4 == 1)
  {
    vL = -100;
    vR = 100;
  }

  if (pin7 == 0 && pin6 == 0 && pin5 == 0 && pin4 == 0)
  {
    vL = -100;
      vR = -100;
      delay(100);
  }
  if (pin7 == 1 && pin6 == 1 && pin5 == 1 && pin4 == 1)
  {
    vL = 0;
    vR = 0;
    servoL.writeMicroseconds(1500 + vL);      // Stops for half a second
    servoR.writeMicroseconds(1500 - vR);
    delay(500);
    vL = 100;
    vR = 100;
    servoL.writeMicroseconds(1500 + vL);      // Move forward - delay is so it doesnt immediately stop again
    servoR.writeMicroseconds(1500 - vR);
    delay(200);
  }

  servoL.writeMicroseconds(1500 + vL);      // Steer robot to recenter it over the line
  servoR.writeMicroseconds(1500 - vR);

  delay(10);                                // Delay for 10 milliseconds (1/100 second)
}
