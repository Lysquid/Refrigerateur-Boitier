#include <packet.h>

void humiditeSetup();
void gazSetup();
void luminositeSetup();
void temperatureSetup();
void codebarreSetup();
void emetteurSetup();

payload_t humiditeLoop(payload_t);
payload_t gaz_loop(payload_t);
payload_t luminositeLoop(payload_t);
payload_t temperatureLoop(payload_t);
payload_t codebarreLoop(payload_t);
void emetteurLoop(payload_t);
