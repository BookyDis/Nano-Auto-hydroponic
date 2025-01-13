#include <stdio.h>
#include "stm32f7xx_hal.h"
#include "button.h"

GPIO_InitTypeDef button_GPIO;

// init GPIO for  
void button_GPIO_Init(void) {
	
    //enable GPIOC clock
    __HAL_RCC_GPIOC_CLK_ENABLE();
    //configure GPIO pin 
    button_GPIO.Pin = GPIO_PIN_6;
    button_GPIO.Mode = GPIO_MODE_INPUT;
    button_GPIO.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &button_GPIO);
    
}
