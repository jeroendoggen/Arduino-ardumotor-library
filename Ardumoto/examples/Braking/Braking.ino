#include <ArduMoto.h>

ArduMoto Moto;

void setup()
{
  Serial.begin(115200);
  Moto.begin();
}

void loop()
{
  Moto.setSpeed('A',80);
  delay (2000);

  Moto.brake('A');
  delay (2000);

  Moto.setSpeed('B',-80);
  delay (2000);

  Moto.brake('B');
  delay (2000);
}
