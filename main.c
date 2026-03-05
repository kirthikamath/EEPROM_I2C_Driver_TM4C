#include <stdio.h>
#include "Inc/eeprom.h"
int main()
{
  uint8_t data_read;
  EEPROM_Init();
  EEPROM_WriteBytes(10,0x55);
  EEPROM_ReadByte(10,&data_read);
  printf("Data read from EEPROM : 0x%X\n", data_read);
  return 0;
}
