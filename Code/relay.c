#include <stdio.h>
#include "stm32f7xx_hal.h"
#include "relay.h"

GPIO_InitTypeDef relay_gpio;

void relay_init(void) {
    //enable the GPIO clock
    __HAL_RCC_GPIOI_CLK_ENABLE();
    
	  //Config for GPIO I2	
    relay_gpio.Pin = GPIO_PIN_2;
	  relay_gpio.Mode = GPIO_MODE_OUTPUT_PP;
    relay_gpio.Pull = GPIO_NOPULL;
    relay_gpio.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOI, &relay_gpio);
   
}


void relay_on(void) {
    HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);
}


void relay_off(void) {
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_RESET);
}