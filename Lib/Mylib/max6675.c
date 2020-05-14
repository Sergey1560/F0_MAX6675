#include "max6675.h"


volatile temperature_TypeDef temp;

void max6675_init(void){
    spi_init();

};	

temperature_TypeDef max6675_gettemp(void){
    static uint8_t first_run=1;
    int16_t retval;

    MAX6675_CS_L;
    retval=(int16_t)spi_send();
    MAX6675_CS_H;

    retval = (retval >> 3);
    temp.raw_value = retval;
    temp.raw_temp = retval * 25;
    if(first_run){
        temp.filtred_temp = temp.raw_temp;
        first_run=0;
    }else{
        temp.filtred_temp = (int16_t)((float)temp.filtred_temp * (1.0 - LOW_PASS_K) + LOW_PASS_K * (float)temp.raw_temp);
    }
    return temp;
}
