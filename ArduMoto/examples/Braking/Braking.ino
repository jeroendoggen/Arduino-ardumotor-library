// Braking.ino - Arduino sketch to show a braking example of a DC motor using the Ardumoto Shield
// Copyright 2012-2013 Jeroen Doggen (jeroendoggen@gmail.com)
//
// Program flow:
//   - start motor at 100% speed
//   - brake motor
//   - set motor speed to 100%
//   - set motor speed to 0% (motor slows down slowly)
//   - start motor at 100% speed
//   - brake motor agressively

#include <Ardumoto.h>

Ardumoto Moto;

void setup()
{
  Serial.begin(115200);
  Moto.begin();
}

void loop()
{
  Moto.setSpeed('A',100);                         // Start motor A
  delay (2000);

  Moto.brake('A');                                // Brake motor A (slowly...)
  delay (2000);

  Moto.setSpeed('A',100);                         // Start motor A
  delay (2000);

  Moto.setSpeed('A',0);                           // Stop motor A (free running)
  delay (2000);

  Moto.setSpeed('A',100);                         // Start motor A
  delay (2000);

  Moto.brakeAgressive('A');                       // Brake motor A (By putting the motor in reverse direction!)
  delay (2000);
}
