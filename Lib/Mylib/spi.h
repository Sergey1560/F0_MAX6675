#ifndef SPI_H
#define SPI_H
#include "common_defs.h"

#define MAX6675_CS_L        GPIOA->BSRR = GPIO_BSRR_BR_4
#define MAX6675_CS_H        GPIOA->BSRR = GPIO_BSRR_BS_4


//Для доступа по 8бит
#define SPI1_DR_8b          (*(__IO uint8_t *)((uint32_t)SPI1+0x0C))
#define SPI1_DR_16b         (*(__IO uint16_t *)((uint32_t)SPI1+0x0C))

void spi_init(void);
uint16_t spi_send(void);

#endif
