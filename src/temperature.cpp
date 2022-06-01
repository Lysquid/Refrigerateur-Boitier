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
  Serial.print("Temperature  : ");

  float anaValue = analogRead(anaPinTemperature);
  float tension = anaValue * 5.0 / 1023.0;
  // temperature = (tension-1.25)/0.25;
  // à la sortie de notre interface, on a Vout(T) = 0.25*T+1.25 d'après la simulation theorique
  // experimentalement, on calibre notre capteur en ajoutant un gain de 0.95 et un offset de -0.55
  // après recalibrage pour la nouvelle architecture, nous obtenons les valeurs suivantes :
  temperature2 = 16.35 * (tension - 3.17);

  if (tension == 5)
  {
    Serial.print("> 30");
  }
  else if (tension == 0)
  {
    Serial.print("< -10");
  }
  else
  {
    Serial.print(temperature2);
  }
  Serial.print("°C (");
  Serial.print(tension);
  Serial.println("V)");

  paquetInfos.temperature = temperature2 * 100;
  return paquetInfos;
}
