#ifndef MAX6675_H
#define MAX6675_H
#include "common_defs.h"
#include "spi.h"


#define LOW_PASS_K  (float)0.1


typedef struct {
    int16_t raw_temp;
    int16_t filtred_temp;
    uint16_t raw_value;
} temperature_TypeDef;




void max6675_init(void);
temperature_TypeDef max6675_gettemp(void);

#endif


