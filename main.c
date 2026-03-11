#include <stdio.h>
#include "Inc/eeprom.h"
int main()
{
  uint8_t write_buffer[5]={10,20,30,40,50};
  uint8_t read_buffer[5];
  uint16_t i;
  uint8_t data_read;
  EEPROM_Init();
  
  /*Test single byte write*/
  EEPROM_WriteBytes(10,0x55);
  EEPROM_ReadByte(10,&data_read);
  printf("Data read from EEPROM : 0x%X\n", data_read);

  /*Test page write*/
  EEPROM_WritePage(20,write_buffer,5);
  for(i=0;i<5;i++)//reading the data from the eeprom
    {
      EEPROM_ReadByte(20+i,&data_read);
      printf("Address %d Data %d\n",20+i,data_read);
    }
  return 0;
  
  /*Test read buffer*/
  EEPROM_ReadBuffee(20,read_buffer,5);
  printf("\nBuffer Read Test\n");
  for( i=0; i<5; i++)
    {
      printf("Buffer[%d] = %d\n",i, read_buffer[i]);
    }
}
