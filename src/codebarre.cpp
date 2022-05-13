#include <Arduino.h>
#include <paquetCodebarre.h>
#include <declarations.h>
#include <stdio.h>

#define BUFF_MAXLEN 64
char barcodeBuffer[BUFF_MAXLEN];
char stringBuffer[14] = {0};

void clearBarcodeBuffer();

unsigned long calculCodebarre(char a[64], int start, int end)
{
  unsigned long num = 0;
  for (int i = start; i < 7; i++)
  {
    char val = a[i];
    num = (val - '0') + (num * 10);
    Serial.println(num);
  }
  return num;
}

unsigned long calculCode1(char a[64])
{
  return calculCodebarre(a, 0, 7);
}

unsigned long calculCode2(char a[64])
{
  return calculCodebarre(a, 8, 13);
}

void codebarreSetup()
{
  clearBarcodeBuffer();
}

paquetCodebarre_t codebarreLoop(paquetCodebarre_t paquetCodebarre)
{
  while (Serial.available() > 0)
  {
    clearBarcodeBuffer();
    Serial.readBytes(barcodeBuffer, BUFF_MAXLEN);
    Serial.print("Code barre   : ");

    unsigned long code1 = 0;
    unsigned long code2 = 0;

    for (int i = 0; i < 7; i++)
    {
      code1 = (barcodeBuffer[i] - '0') + (code1 * 10);
    }
    for (int i = 7; i < 13; i++)
    {
      code2 = (barcodeBuffer[i] - '0') + (code2 * 10);
    }

    Serial.print(code1);
    Serial.println(code2);

    paquetCodebarre.codeBarre1 = code1;
    paquetCodebarre.codeBarre2 = code2;
  }
  return paquetCodebarre;
}

void clearBarcodeBuffer()
{
  for (int i = 0; i < BUFF_MAXLEN; i++)
  {
    barcodeBuffer[i] = (char)0;
  }
}
