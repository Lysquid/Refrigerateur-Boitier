#define BUFF_MAXLEN 64
char barcodeBuffer[BUFF_MAXLEN];

void clearBarcodeBuffer();

void codebarreSetup()
{
  clearBarcodeBuffer();
}

payload_t codebarreLoop(payload_t packet)
{
  while (Serial.available() > 0)
  {
    clearBarcodeBuffer();
    Serial.readBytes(barcodeBuffer, BUFF_MAXLEN);
    Serial.print("Code barre   : ");
    Serial.println(barcodeBuffer);
    packet.codeBarre = barcodeBuffer[0];
  }
  return packet;
}

void clearBarcodeBuffer()
{
  for (int i = 0; i < BUFF_MAXLEN; i++)
  {
    barcodeBuffer[i] = (char)0;
  }
}
