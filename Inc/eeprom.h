#ifndef EEPROM_H
#define EEPROM_H

#include <stdint.h>

/*
 * EEPROM device configuration
 * Assumes external I2C EEPROM (24xx series)
 * Page size is used to avoid page boundary write issues
 */
#define EEPROM_I2C_ADDRESS   0x50
#define EEPROM_PAGE_SIZE     64

/*
 * Initializes the I2C peripheral required for EEPROM communication
 */
void EEPROM_Init(void);

/*
 * Writes a single byte to EEPROM
 *
 * @param mem_addr : EEPROM internal memory address
 * @param data     : Byte to be written
 *
 * @return status (0 = success, negative = error)
 */
int EEPROM_WriteByte(uint16_t mem_addr, uint8_t data);

/*
 * Reads a single byte from EEPROM
 *
 * @param mem_addr : EEPROM internal memory address
 * @param data     : Pointer to store the read byte
 *
 * @return status (0 = success, negative = error)
 */
int EEPROM_ReadByte(uint16_t mem_addr, uint8_t *data);

/*
 * Writes multiple bytes to EEPROM with page-safe handling
 */
int EEPROM_WriteBuffer(uint16_t mem_addr, uint8_t *data, uint16_t length);

/*
 * Reads multiple bytes from EEPROM
 */
int EEPROM_ReadBuffer(uint16_t mem_addr, uint8_t *data, uint16_t length);

#endif /* EEPROM_H */
