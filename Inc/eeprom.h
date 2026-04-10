#ifndef EEPROM_H
#define EEPROM_H

#include <stdint.h>

/*
 * EEPROM device configuration
 * Assumes external I2C EEPROM (24xx series)
 * Page size is used to avoid page boundary write issues
 */
#define EEPROM_I2C_ADDRESS   0x50
#define EEPROM_SIZE_BYTES    32768
#define EEPROM_PAGE_SIZE     64
#define EEPROM_MAX_ADDR      0x7FFF

#define EEPROM_OK 0
#define EEPROM_ERROR 1
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
uint8_t EEPROM_WriteByte(uint16_t address, uint8_t data);

/*
 * Reads a single byte from EEPROM
 *
 * @param mem_addr : EEPROM internal memory address
 * @param data     : Pointer to store the read byte
 *
 * @return status (0 = success, 1 = error)
 */
uint8_t EEPROM_ReadByte(uint16_t address, uint8_t *data);

/*
 * Function: EEPROM_WritePage
 * Description:
 * Writes multiple bytes of data to the EEPROM starting from
 * the specified memory address. The number of bytes written
 * must not exceed the EEPROM page size.
 * Parameters:
 * address : Starting EEPROM memory address where data
 *           will be written.
 
 * data    : Pointer to the data buffer that contains
 *           bytes to be written to EEPROM.
 * length  : Number of bytes to write. Must be less than
 *           or equal to EEPROM_PAGE_SIZE.
 * Returns:
 * 0  -> Success
 * 1  -> Error (invalid address or length exceeds page size)
 * Notes:
 * This function simulates page write behaviour of EEPROM
 * devices which allow writing only one page at a time.
 */
uint8_t EEPROM_WritePage(uint16_t address,uint8_t *data,uint16_t length);

/*
 * Writes multiple bytes to EEPROM with page-safe handling
 */
/*int EEPROM_WriteBuffer(uint16_t mem_addr, uint8_t *data, uint16_t length);*/

/*
 *EEPROM_ReadBuffer
 * Reads multiple bytes from EEPROM starting at address into buffer.
 *length specifies the number of bytes to read.
 *returns EEPROM_OK on success, EEPROM_ERROR on invalid address or null pointer.
 */
uint8_t EEPROM_ReadBuffer(uint16_t address, uint8_t *buffer, uint16_t length);

/*
 * Writing
 multiple bytes from EEPROM
 */
uint8_t EEPROM_WriteBuffer(uint16_t address, uint8_t *buffer, uint16_t length);

uint8_t EEPROM_IsValidAddress(uint16_t address);

/*Hardware abstraction layer*/

uint8_t EEPROM_HW_Write(uint16_t mem_addr, uint8_t *data, uint16_t len);
uint8_t EEPROM_HW_Read(uint16_t mem_addr, uint8_t *data, uint16_t len);

#endif /* EEPROM_H */
