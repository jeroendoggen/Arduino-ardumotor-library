// FadSpeed.ino - Arduino sketch to show a fading example of a DC motor using the ArduMoto Shield
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
//
// Program flow:
//   - fade motor speed to +100% (motor should accelerate slowly)
//   - fade motor speed to -100% (motor should slow down en slowly reverse direction)
//   - set motor at 100% speed (sudden change in motor speed to 100%)
//   - set motor at 100% speed (sudden change in motor speed to -100%)

#include <ArduMoto.h>

ArduMoto Moto;

void setup()
{
  Serial.begin(115200);
  Moto.begin();
}

void loop()
{
  Moto.fadeSpeed('A',100);
  delay (2000);
  Moto.fadeSpeed('A',-100);
  delay (2000);
  Moto.setSpeed('A',100);
  delay (2000);
  Moto.setSpeed('A',-100);
  delay (2000);
}
