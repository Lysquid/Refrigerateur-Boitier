#include <Arduino.h>
#include <paquets.h>
#include <declarations.h>
#include <SPI.h>
#include <RF24.h>

RF24 radio(9, 10);
uint8_t address[6] = {80, 0xCE, 0xCC, 0xCE, 0xCC}; // Adresse du pipe

void emetteurSetup()
{

  radio.begin();
  radio.setChannel(80);
  radio.setDataRate(RF24_2MBPS);
  radio.openWritingPipe(address); // Ouvrir le Pipe en écriture
  radio.stopListening();

  radio.setPALevel(RF24_PA_MAX);
  radio.setRetries(15, 15);
  radio.enableDynamicPayloads();
}

void emetteurLoop(paquetInfos_t paquetInfos)
{
  Serial.print("Transmission : ");

  long time1 = millis();
  bool test;
  test = radio.write(&paquetInfos, sizeof(paquetInfos));

  if (test)
  {
    Serial.print("reussie.");
  }
  else
  {
    Serial.print("echoue.");
  }
  long time2 = millis();
  Serial.println(" temps ecoule : " + String(time2 - time1) + "ms");
}

void emetteurPorte(paquetPorte_t paquetPorte)
{
  radio.write(&paquetPorte, sizeof(paquetPorte));
}

void emetteurCodebarre(paquetCodebarre_t paquetCodebarre)
{
  radio.write(&paquetCodebarre, sizeof(paquetCodebarre));
}