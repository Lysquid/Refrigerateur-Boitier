#include <Arduino.h>
#include <packet.h>

#include <Humidite.h>
#include <Gaz.h>
#include <Luminosite.h>
#include <Temperature.h>
#include <Codebarre.h>
#include <Emetteur.h>

const bool humidite = 1;
const bool gaz = 1;
const bool luminosite = 1;
const bool codebarre = 1;
const bool temperature = 1;
const bool emetteur = 1;

payload_t packet;

void setup()
{
    Serial.begin(115200);
    while (!Serial)
    {
        delay(10);
    }
    Serial.println("Set up debut");

    if (humidite)
        humiditeSetup();
    if (gaz)
        gazSetup();
    if (luminosite)
        luminositeSetup();
    if (temperature)
        temperatureSetup();
    if (codebarre)
        codebarreSetup();
    if (emetteur)
        emetteurSetup();

    Serial.println("Set up fin");
}

void loop()
{
    Serial.println();

    if (humidite)
        packet = humiditeLoop(packet);
    if (gaz)
        packet = gaz_loop(packet);
    if (luminosite)
        packet = luminositeLoop(packet);
    if (temperature)
        packet = temperatureLoop(packet);
    if (codebarre)
        packet = codebarreLoop(packet);
    if (emetteur)
        emetteurLoop(packet);

    delay(1000);
}
