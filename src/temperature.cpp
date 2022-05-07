#include <Arduino.h>
#include <packet.h>
#include <declarations.h>

int anaPinTemperature = A0;
float temperature2;

void temperatureSetup()
{
}

payload_t temperatureLoop(payload_t packet)
{
  Serial.print("Temperature  : ");

  float anaValue = analogRead(anaPinTemperature);
  float tension = anaValue * 5.0 / 1023.0;
  // temperature = (tension-1.25)/0.25;
  // à la sortie de notre interface, on a Vout(T) = 0.25*T+1.25 d'après la simulation theorique
  // experimentalement, on calibre notre capteur en ajoutant un gain de 0.95 et un offset de -0.55
  temperature2 = 3.36 * tension - 4.75;

  if (tension == 5)
  {
    Serial.print("> 12.05");
  }
  else if (tension == 0)
  {
    Serial.print("< -4.75");
  }
  else
  {
    Serial.print(temperature2);
  }
  Serial.println("°C");

  packet.temperature = temperature2 * 100;
  return packet;
}
