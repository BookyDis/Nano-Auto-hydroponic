#include <stdio.h>
#include "stm32f7xx_hal.h"
#include "led.h"

GPIO_InitTypeDef led_GPIO;

 
void led_GPIO_Init(void) {
	   
    //enable GPIO clock
    __HAL_RCC_GPIOC_CLK_ENABLE();
    //configure GPIO pin 
    led_GPIO.Pin = GPIO_PIN_7;
    led_GPIO.Mode = GPIO_MODE_OUTPUT_PP;
    led_GPIO.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &led_GPIO);
    
}

void led_on() {
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);
}

void led_off() {
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);
}
