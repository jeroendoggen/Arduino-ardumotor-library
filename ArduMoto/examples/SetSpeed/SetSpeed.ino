// FadSpeed.ino - Arduino sketch to show a fading example of a DC motor using the Ardumoto Shield
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
//
// Program flow:
//   - set motor speed at 30%
//   - set motor speed at 60%
//   - set motor speed at 90%
//   - set motor speed at 60%
//   - set motor speed at 30%
//   - set motor speed at 0%

#include <Ardumoto.h>

Ardumoto Moto;

void setup()
{
  Serial.begin(115200);
  Moto.begin();
}

void loop()
{
  Moto.setSpeed('A',30);
  delay (2000);

  Moto.setSpeed('A',60);
  delay (2000);

  Moto.setSpeed('A',90);
  delay (2000);

  Moto.setSpeed('A',60);
  delay (2000);

  Moto.setSpeed('A',30);
  delay (2000);

  Moto.setSpeed('A',0);
  delay (2000);
}
