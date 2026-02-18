#ifndef EEPROM_H
#define EEPROM_H

#include <stdint.h>

/* EEPROM configuration */
#define EEPROM_SIZE_BYTES   1024
#define EEPROM_PAGE_SIZE    16

/* EEPROM API */
void EEPROM_Init(void);
uint8_t EEPROM_WriteByte(uint16_t address, uint8_t data);
uint8_t EEPROM_ReadByte(uint16_t address, uint8_t *data);

#endif /* EEPROM_H */
