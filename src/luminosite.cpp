#include <Arduino.h>
#include <packet.h>
#include <declarations.h>

int pinLuminosite = A1;

void luminositeSetup()
{
}

payload_t luminositeLoop(payload_t packet)
{
    Serial.print("Luminosite   : ");

    // read the input on analog pin 0:
    int sensorValue = analogRead(pinLuminosite);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = sensorValue * (5.0 / 1024.0);

    // the lower the voltage, the brighter it is
    if ((voltage >= 0) && (voltage <= 0.4))
    {
        Serial.print("lumineux : ");
    }
    else if ((voltage > 0.4) && (voltage <= 2))
    {
        Serial.print("peu lumineux : ");
    }
    else
    {
        Serial.print("sombre : ");
    }
    // print out the value you read:
    Serial.print(voltage);
    Serial.println("V");

    // D0:

    // when sensor pin D0 is connected, the sensor only knows the state light (0.14V) and dark (5.0V).
    // The brightness at which the particular state is to be set can be set using the rotary potentiometer.

    packet.luminosite = voltage < 2;
    return packet;
}
