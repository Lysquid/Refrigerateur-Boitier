#include <Arduino.h>
#include <paquetCodebarre.h>
#include <paquetInfos.h>
#include <paquetPorte.h>
#include <declarations.h>

const bool humidite = 1;
const bool gaz = 1;
const bool luminosite = 1;
const bool codebarre = 1;
const bool temperature = 1;
const bool emetteur = 1;

paquetCodebarre_t paquetCodebarre;
paquetInfos_t paquetInfos;
paquetPorte_t paquetPorte;

void setup()
{
    Serial.begin(115200);
    while (!Serial)
    {
        delay(10);
    }
    Serial.println("\n");
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
        paquetInfos = humiditeLoop(paquetInfos);
    if (gaz)
        paquetInfos = gaz_loop(paquetInfos);
    if (luminosite)
        paquetPorte = luminositeLoop(paquetPorte);
    if (temperature)
        paquetInfos = temperatureLoop(paquetInfos);
    if (codebarre)
        paquetCodebarre = codebarreLoop(paquetCodebarre);
    if (emetteur)
        emetteurLoop(paquetInfos, paquetPorte, paquetCodebarre);

    delay(1000);
}
