#include <ArduMoto.h>

ArduMoto Moto;

void setup()
{
  Serial.begin(115200);
  Moto.begin();
}

void loop()
{
  Moto.setSpeed('A',10);
  delay (2000);

  Moto.setSpeed('A',70);
  delay (2000);

  Moto.setSpeed('A',100);
  delay (2000);

  Moto.setSpeed('A',50);
  delay (2000);

  Moto.setSpeed('A',0);
  delay (2000);

  Moto.setSpeed('B',-50);
  delay (2000);

  Moto.setSpeed('B',-80);
  delay (2000);

  Moto.setSpeed('B',-100);
  delay (2000);

  Moto.setSpeed('B',-50);
  delay (2000);

  Moto.setSpeed('B',0);
  delay (2000);
}
