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

uint8_t EEPROM_IsValidAddress(uint16_t address)
{
    if(address >= EEPROM_SIZE_BYTES)
    {
        return EEPROM_ERROR;
    }
    return EEPROM_OK;
}

/*
 * EEPROM_WriteByte
 * ----------------
 * Writes a single byte to EEPROM at given address.
 * Returns 0 on success, non-zero on error.
 */
uint8_t EEPROM_WriteByte(uint16_t address, uint8_t data)
{
    if(EEPROM_IsValidAddress(address) == EEPROM_ERROR)
    {
        return EEPROM_ERROR;//error
    }
    eeprom_memory[address]= data;
    return EEPROM_OK;//success
}

/*
 * EEPROM_ReadByte
 * ---------------
 * Reads a single byte from EEPROM at given address.
 * Returns 0 on success, non-zero on error.
 */
uint8_t EEPROM_ReadByte(uint16_t address, uint8_t *data)
{
    if(EEPROM_IsValidAddress(address) == EEPROM_ERROR ||data == NULL)
    {
        return EEPROM_ERROR;
    }
    *data = eeprom_memory[address];
    return EEPROM_OK;
}

uint8_t EEPROM_WritePage(uint16_t address,uint8_t *data, uint16_t length)
{
    uint16_t i;
    if((address+length )> EEPROM_SIZE_BYTES)//prevents writing outside memory.
    {
        return EEPROM_ERROR;
    }
    if (length > EEPROM_PAGE_SIZE)//real eeprom chips allow writing only one page at a time
    {
        return EEPROM_ERROR;
    }
    if((address/EEPROM_PAGE_SIZE)!=((address+length-1)/EEPROM_PAGE_SIZE)) //check page boundary crossing
    {
        return EEPROM_ERROR;
    }
    for (i=0; i< length; i++) //copies each byte from buffer to eeprom memory
    {
        eeprom_memory[address+i]=data[i];
    }
    return EEPROM_OK;
    
}

uint8_t EEPROM_ReadBuffer(uint16_t address,uint8_t *buffer,uint16_t length)
{
    uint16_t i;
    /*checj=k if read exceeds memory size*/
    if((address+length)> EEPROM_SIZE_BYTES)
    {
        return EEPROM_ERROR;
    }
    for(i=0;i<length;i++)
    {
        buffer[i]= eeprom_memory[address+i];
    }
    return EEPROM_OK;
}

