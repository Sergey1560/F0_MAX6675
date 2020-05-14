#include "main.h"

uint8_t CDC_Transmit_FS(uint8_t* Buf, uint16_t Len);


void timer3_init(void){
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3->PSC = 48000000/1000 - 1;
	TIM3->ARR = 200;
	TIM3->DIER |= TIM_DIER_UIE;
	TIM3->CR1 |= TIM_CR1_CEN;
	NVIC_EnableIRQ(TIM3_IRQn);
}

void TIM3_IRQHandler(void)
{
	temperature_TypeDef temp;
	char str[20];

	if(TIM3->SR & TIM_SR_UIF) TIM3->SR &= ~TIM_SR_UIF;

	temp = max6675_gettemp();

	sprintf(str,"%d:%d\n",temp.filtred_temp,temp.raw_temp);
	CDC_Transmit_FS((uint8_t *)str,strlen(str));
	DEBUG("Temp %d RAW %d",temp.filtred_temp,temp.raw_temp);
	
 }


int main(void)
{
	HAL_Init();

	RCC_init();
	Delay_Init();
	
  	MX_USB_DEVICE_Init();

	max6675_init();	
	timer3_init();
	while(1){
	}
}

void SystemClock_Config(void){
	RCC_init();
};

void Error_Handler(void){
}
