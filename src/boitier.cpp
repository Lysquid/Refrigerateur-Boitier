#include <Arduino.h>
#include <paquets.h>
#include <declarations.h>

const bool temperature = 1;
const bool humidite = 1;
const bool gaz = 1;
const bool luminosite = 1;
const bool codebarre = 1;
const bool emetteur = 1;

const int delai = 1000;
const int nombreBoucles = 5;

void setup()
{
    Serial.begin(115200);
    while (!Serial)
    {
        delay(10);
    }
    Serial.println("\n");
    Serial.println("Set up debut");

    if (temperature)
        temperatureSetup();
    if (humidite)
        humiditeSetup();
    if (gaz)
        gazSetup();
    if (luminosite)
        luminositeSetup();
    if (codebarre)
        codebarreSetup();
    if (emetteur)
        emetteurSetup();

    Serial.println("Set up fin");
}

void loop()
{

    paquetInfos_t paquetInfos;

    Serial.println();

    if (temperature)
        paquetInfos = temperatureLoop(paquetInfos);
    if (humidite)
        paquetInfos = humiditeLoop(paquetInfos);
    if (gaz)
        paquetInfos = gaz_loop(paquetInfos);
    if (emetteur)
        emetteurLoop(paquetInfos);

    for (int i = 0; i < nombreBoucles; i++)
    {
        if (luminosite)
            luminositeLoop(emetteur);
        if (codebarre)
            codebarreLoop(emetteur);
        delay(delai / nombreBoucles);
    }
}
