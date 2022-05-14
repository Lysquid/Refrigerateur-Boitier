#include <Arduino.h>
#include <paquets.h>
#include <declarations.h>

int pinLuminosite = A1;
bool porteOuverte = true;

void luminositeSetup()
{
}

void luminositeLoop(boolean emission)
{

    int sensorValue = analogRead(pinLuminosite);
    float tension = sensorValue * (5.0 / 1024.0);

    bool precPorteOuverte = porteOuverte;
    porteOuverte = tension < 2.5;

    if (porteOuverte != precPorteOuverte)
    {
        Serial.print("Luminosite   : Porte ");
        if (porteOuverte)
            Serial.print("ouverte.");
        else
            Serial.print("fermée.");

        Serial.print(" tension : ");
        Serial.print(tension);
        Serial.println("V");

        if (emission)
        {

            paquetPorte_t paquetPorte;
            paquetPorte.porteOuverte = porteOuverte;
            emetteurPorte(paquetPorte);
        }
    }

    // D0: when sensor pin D0 is connected, the sensor only knows the state light (0.14V) and dark (5.0V).
    // The brightness at which the particular state is to be set can be set using the rotary potentiometer.
}
