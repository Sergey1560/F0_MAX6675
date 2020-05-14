#include "main.h"


void timer3_init(void){
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3->PSC = 48000000/1000 - 1;
	TIM3->ARR = 500;
	TIM3->DIER |= TIM_DIER_UIE;
	TIM3->CR1 |= TIM_CR1_CEN;
	NVIC_EnableIRQ(TIM3_IRQn);
}

void TIM3_IRQHandler(void)
{
	static uint8_t prescaler=0;
	temperature_TypeDef temp;
	
	if(TIM3->SR & TIM_SR_UIF) TIM3->SR &= ~TIM_SR_UIF;

	temp = max6675_gettemp();

	if(prescaler == 5){
		DEBUG("Temp %d RAW %d",temp.filtred_temp,temp.raw_temp);
	 	prescaler=0;
	}else{
		prescaler++;
	}
}


int main(void)
{
	RCC_init();
	Delay_Init();

	max6675_init();	
	timer3_init();
	while(1){
	}
}
