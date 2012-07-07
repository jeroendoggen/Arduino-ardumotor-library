#include <ArduMoto.h>

ArduMoto Moto;

void setup()
{
  Serial.begin(115200);
  Moto.begin();
}

void loop()
{
  Moto.fadeSpeed('A',50);
  delay (2000);
  Moto.fadeSpeed('A',100);
  delay (2000);
  Moto.fadeSpeed('A',-50);
  delay (2000);
  Moto.fadeSpeed('A',0);
  delay (2000);

  Moto.fadeSpeed('B',50);
  delay (2000);
  Moto.fadeSpeed('B',100);
  delay (2000);
  Moto.fadeSpeed('B',-50);
  delay (2000);
  Moto.fadeSpeed('B',0);
  delay (2000);
}
