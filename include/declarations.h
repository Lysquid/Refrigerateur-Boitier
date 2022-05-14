#include <paquets.h>

void humiditeSetup();
void gazSetup();
void luminositeSetup();
void temperatureSetup();
void codebarreSetup();
void emetteurSetup();

paquetInfos_t humiditeLoop(paquetInfos_t);
paquetInfos_t gaz_loop(paquetInfos_t);
paquetInfos_t temperatureLoop(paquetInfos_t);
void codebarreLoop(bool);
void luminositeLoop(bool);
void emetteurLoop(paquetInfos_t);
void emetteurPorte(paquetPorte_t);
void emetteurCodebarre(paquetCodebarre_t);
