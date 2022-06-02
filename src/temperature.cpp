#include <Arduino.h>
#include <paquets.h>
#include <declarations.h>

int anaPinTemperature = A0;
float temperature2;

void temperatureSetup()
{
}

paquetInfos_t temperatureLoop(paquetInfos_t paquetInfos)
{
  float anaValue = analogRead(anaPinTemperature);
  float tension = anaValue * 5.0 / 1024.0;

  Serial.print("Temperature  : ");
  Serial.print(tension);
  Serial.println("V");

  paquetInfos.temperature = tension * 100;
  return paquetInfos;
}
