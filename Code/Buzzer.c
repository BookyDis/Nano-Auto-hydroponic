#include <stdio.h>
#include "stm32f7xx_hal.h"
#include "Buzzer.h"

GPIO_InitTypeDef sound_gpio;
//config sound
void buzzer_init(void) {
    //enable the GPIO clock
    __HAL_RCC_GPIOA_CLK_ENABLE();
    
	  //config for GPIO A15
    sound_gpio.Pin = GPIO_PIN_15;
	  sound_gpio.Mode = GPIO_MODE_OUTPUT_PP;
    sound_gpio.Pull = GPIO_NOPULL;
    sound_gpio.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOA, &sound_gpio);
   
}


void buzzer_on(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
}


void buzzer_off(void) {
	
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
    
}