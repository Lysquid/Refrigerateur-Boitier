#include <Arduino.h>
#include <packet.h>
#include <declarations.h>
#include <SPI.h>
#include <RF24.h>

RF24 radio(9, 10);
uint8_t address[6] = {80, 0xCE, 0xCC, 0xCE, 0xCC}; // Adresse du pipe
// payload_t val;  Valeur à envoyer
long time1;
long time2;

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

void emetteurLoop(payload_t packet)
{
  Serial.print(F("\n Now sending Packet "));

  time1 = micros();
  if (radio.write(&packet, sizeof(packet)))
  {
    Serial.print(F(" ... Ok ... "));
  }
  else
  {
    Serial.print(F(" ... failed ... "));
  }
  time2 = micros();
  Serial.println("temps ecoule: " + String(time2 - time1) + " µs");
}
