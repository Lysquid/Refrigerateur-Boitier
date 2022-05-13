#include <paquetCodebarre.h>
#include <paquetInfos.h>
#include <paquetPorte.h>

void humiditeSetup();
void gazSetup();
void luminositeSetup();
void temperatureSetup();
void codebarreSetup();
void emetteurSetup();

paquetInfos_t humiditeLoop(paquetInfos_t);
paquetInfos_t gaz_loop(paquetInfos_t);
paquetPorte_t luminositeLoop(paquetPorte_t);
paquetInfos_t temperatureLoop(paquetInfos_t);
paquetCodebarre_t codebarreLoop(paquetCodebarre_t);
void emetteurLoop(paquetInfos_t, paquetPorte_t, paquetCodebarre_t);
