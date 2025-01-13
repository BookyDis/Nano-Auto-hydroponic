#include <stdio.h>
#include "stm32f7xx_hal.h"
#include "watersensor.h"

GPIO_InitTypeDef watersensor_gpio;
ADC_ChannelConfTypeDef watersensorConfig;
GPIO_InitTypeDef water_GPIO;

// init ADC configuration 
void water_ADC_Init(void) {	
    //enable ADC clock
    __HAL_RCC_ADC1_CLK_ENABLE();
	
    //configure channel
    watersensorConfig.Rank = 1;
    watersensorConfig.Channel = ADC_CHANNEL_1; //
    watersensorConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES;  
}

//init GPIO for analog 
void water_GPIO_Init(void) {
    //enable GPIOA clock
    __HAL_RCC_GPIOA_CLK_ENABLE();
    //config mode to analog
    water_GPIO.Pin = GPIO_PIN_0; 
    water_GPIO.Mode = GPIO_MODE_ANALOG;
    water_GPIO.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &water_GPIO);
}

void water_Config(void){
	
	water_GPIO_Init();
	water_ADC_Init();
	
}

