/*EEPROM driver source file*/
#include "eeprom.h"

/*
 * EEPROM_Init
 * -------------
 * Initializes EEPROM interface.
 * Hardware-specific I2C initialization
 * will be added later.
 */
void EEPROM_Init(void)
{
    /* To be implemented */
}

/*
 * EEPROM_WriteByte
 * ----------------
 * Writes a single byte to EEPROM at given address.
 * Returns 0 on success, non-zero on error.
 */
uint8_t EEPROM_WriteByte(uint16_t address, uint8_t data)
{
    /* To be implemented */
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
    /* To be implemented */
    return 0;
}
