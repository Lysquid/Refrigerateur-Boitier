#include <Arduino.h>
#include <paquetInfos.h>
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

paquetInfos_t gaz_loop(paquetInfos_t paquetInfos)
{
    Serial.print("Gaz          : ");

    Serial.print("NH3: ");
    paquetInfos.gaz[0] = gas.measure_NH3();
    Serial.print(paquetInfos.gaz[0]);
    Serial.print("ppm, ");

    Serial.print("CO: ");
    paquetInfos.gaz[1] = gas.measure_CO();
    Serial.print(paquetInfos.gaz[1]);
    Serial.print("ppm, ");

    Serial.print("NO2: ");
    paquetInfos.gaz[2] = gas.measure_NO2();
    Serial.print(paquetInfos.gaz[2]);
    Serial.print("ppm, ");

    Serial.print("C3H8: ");
    paquetInfos.gaz[3] = gas.measure_C3H8();
    Serial.print(paquetInfos.gaz[3]);
    Serial.print("ppm, ");

    Serial.print("C4H10: ");
    paquetInfos.gaz[4] = gas.measure_C4H10();
    Serial.print(paquetInfos.gaz[4]);
    Serial.print("ppm, ");

    Serial.print("CH4: ");
    paquetInfos.gaz[5] = gas.measure_CH4();
    Serial.print(paquetInfos.gaz[5]);
    Serial.print("ppm, ");

    Serial.print("H2: ");
    paquetInfos.gaz[6] = gas.measure_H2();
    Serial.print(paquetInfos.gaz[6]);
    Serial.print("ppm, ");

    Serial.print("C2H5OH: ");
    paquetInfos.gaz[7] = gas.measure_C2H5OH();
    Serial.print(paquetInfos.gaz[7]);
    Serial.print("ppm");

    Serial.println();

    return paquetInfos;
}
