// Braking.ino - Arduino sketch to show a braking example of a DC motor using the ArduMoto Shield
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
//
// Program flow:
//   - start motor at 100% speed
//   - brake motor (motor should stop suddenly)
//   - set motor speed to -100%
//   - set motor speed to 0% (motor slows down slowly)

#include <ArduMoto.h>

ArduMoto Moto;

void setup()
{
  Serial.begin(115200);
  Moto.begin();
}

void loop()
{
  Moto.setSpeed('A',100);
  delay (2000);

  Moto.brake('A');
  delay (2000);

  Moto.setSpeed('A',-100);
  delay (2000);

  Moto.setSpeed('A',-0);
  delay (2000);
}
