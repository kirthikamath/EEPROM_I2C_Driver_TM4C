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
        return 1;//Invalid address
    }
    eeprom_memory[address]= data;
    return 0;
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
