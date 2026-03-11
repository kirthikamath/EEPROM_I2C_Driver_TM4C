/*EEPROM driver source file*/
#include "eeprom.h"
/*Simulated EEPROM memory*/
static uint8_t eeprom_memory[EEPROM_SIZE_BYTES];
/*
 * EEPROM_Init
 * -------------
 * Initializes EEPROM interface.
 * Hardware-specific I2C initialization
 * will be added later.
 */
void EEPROM_Init(void)
{
    for(uint16_t i=0;i<EEPROM_SIZE_BYTES;i++)
        {
            eeprom_memory[i]=0xFF;
        }
}

/*
 * EEPROM_WriteByte
 * ----------------
 * Writes a single byte to EEPROM at given address.
 * Returns 0 on success, non-zero on error.
 */
uint8_t EEPROM_WriteByte(uint16_t address, uint8_t data)
{
    if(address>=EEPROM_SIZE_BYTES)
    {
        return 1;//error
    }
    eeprom_memory[address]= data;
    return 0;//success
}

/*
 * EEPROM_ReadByte
 * ---------------
 * Reads a single byte from EEPROM at given address.
 * Returns 0 on success, non-zero on error.
 */
uint8_t EEPROM_ReadByte(uint16_t address, uint8_t *data)
{
    if(address>=EEPROM_SIZE_BYTES||data==0)
    {
        return 1;
    }
    *data = eeprom_memory[address];
    return 0;
}

uint8_t EEPROM_WritePage(uint16_t address,uint8_t *data, uint16_t length)
{
    uint16_t i;
    if((address+length )> EEPROM_SIZE_BYTES)//prevents writing outside memory.
    {
        return 1;
    }
    else if (length > EEPROM_PAGE_SIZE)//real eeprom chips allow writing only one page at a time
    {
        return 1;
    }
    else
    {
        for (i=0; i< length; i++) //copies each byte from buffer to eeprom memory
        {
            eeprom_memory[address+i]=data[i];
        }
        return 0;
    }
}

uint8_t EEPROM_ReadBUffer(uint16_t address,uint8_t *buffer,uint16_t length)
{
    uint16_t i;
    /*checj=k if read exceeds memory size*/
    if((address+length)> EEPROM_SIZE_BYTES)
    {
        return 1;
    }
    for(i=0;i<length;i++)
    {
        buffer[i]= eeprom_memory[address+i];
    }
    return 0;
}

