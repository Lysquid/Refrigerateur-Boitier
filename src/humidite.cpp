#include <Arduino.h>
#include <packet.h>
#include <declarations.h>
#include <Adafruit_Si7021.h>

bool enableHeater = false;
uint8_t loopCnt = 0;

Adafruit_Si7021 sensorHumidite = Adafruit_Si7021();

void heater();

void humiditeSetup()
{
  Serial.println("Humidite debut");

  if (!sensorHumidite.begin())
  {
    Serial.println("Did not find sensor!");
    return;
  }
  Serial.print("Found sensor ");
  Serial.print(sensorHumidite.getModel());
  Serial.print(" Rev(");
  Serial.print(sensorHumidite.getRevision());
  Serial.print(")");
  Serial.print(" Serial #");
  Serial.print(sensorHumidite.sernum_a, HEX);
  Serial.println(sensorHumidite.sernum_b, HEX);

  Serial.println("Humidite fin");
}

payload_t humiditeLoop(payload_t packet)
{
  Serial.print("Humidite     : ");
  float humidite = sensorHumidite.readHumidity();
  Serial.print(humidite, 2);
  Serial.print("%\t(Temperature : ");
  float temperature2 = sensorHumidite.readTemperature();
  Serial.print(temperature2, 2);
  Serial.println("°C)");
  heater();

  packet.humidite = humidite * 100;
  packet.temperature2 = temperature2 * 100;
  return packet;
}

void heater()
{
  // Toggle heater enabled state every 30 seconds
  // An ~1.8 degC temperature increase can be noted when heater is enabled
  if (++loopCnt == 30)
  {
    enableHeater = !enableHeater;
    sensorHumidite.heater(enableHeater);
    Serial.print("Heater Enabled State: ");
    if (sensorHumidite.isHeaterEnabled())
      Serial.println("ENABLED");
    else
      Serial.println("DISABLED");

    loopCnt = 0;
  }
}
