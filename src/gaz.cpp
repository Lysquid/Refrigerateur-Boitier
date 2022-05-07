#include <Arduino.h>
#include <packet.h>
#include <declarations.h>
#include <Wire.h>
#include <MutichannelGasSensor.h>

void gazSetup()
{
    Serial.println("Gaz debut");

    gas.begin(0x04); // the default I2C address of the slave is 0x04
    gas.powerOn();

    Serial.println("Gaz fin");
}

payload_t gaz_loop(payload_t packet)
{
    Serial.print("Gaz          : ");

    Serial.print("NH3: ");
    packet.gaz[0] = gas.measure_NH3();
    Serial.print(packet.gaz[0]);
    Serial.print("ppm, ");

    Serial.print("CO: ");
    packet.gaz[1] = gas.measure_CO();
    Serial.print(packet.gaz[1]);
    Serial.print("ppm, ");

    Serial.print("NO2: ");
    packet.gaz[2] = gas.measure_NO2();
    Serial.print(packet.gaz[2]);
    Serial.print("ppm, ");

    Serial.print("C3H8: ");
    packet.gaz[3] = gas.measure_C3H8();
    Serial.print(packet.gaz[3]);
    Serial.print("ppm, ");

    Serial.print("C4H10: ");
    packet.gaz[4] = gas.measure_C4H10();
    Serial.print(packet.gaz[4]);
    Serial.print("ppm, ");

    Serial.print("CH4: ");
    packet.gaz[5] = gas.measure_CH4();
    Serial.print(packet.gaz[5]);
    Serial.print("ppm, ");

    Serial.print("H2: ");
    packet.gaz[6] = gas.measure_H2();
    Serial.print(packet.gaz[6]);
    Serial.print("ppm, ");

    Serial.print("C2H5OH: ");
    packet.gaz[7] = gas.measure_C2H5OH();
    Serial.print(packet.gaz[7]);
    Serial.print("ppm");

    Serial.println();

    return packet;
}
