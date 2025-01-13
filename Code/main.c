#include <stdio.h>
#include <stdio.h>
#include "stm32f7xx_hal.h"
#include <string.h>
#include "relay.h"
#include "buzzer.h"
#include "GLCD.h"
#include "Board_GLCD.h"
#include "Board_Touch.h"
#include "watersensor.h"
#define wait_delay HAL_Delay
#include "button.h"
#include "led.h"

#ifdef __RTX
extern uint32_t os_time;
uint32_t HAL_GetTick(void) {
	return os_time;
}
#endif

ADC_HandleTypeDef hadc1;
ADC_HandleTypeDef hadc2;
HAL_StatusTypeDef HAL_ADC_Stop(ADC_HandleTypeDef* hadc);


int main(void) {
	
    char msg[128];
	  
	  //configure system's clock, RCC and HAL
	  RCC_OscInitTypeDef RCC_OscInitStruct;
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 25;
    RCC_OscInitStruct.PLL.PLLN = 336;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 7;
    HAL_RCC_OscConfig(&RCC_OscInitStruct);
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK |
    RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
     
		//configure hadc 
    hadc1.Instance = ADC1;
    hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
    hadc1.Init.Resolution = ADC_RESOLUTION_10B;
    hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
    hadc1.Init.NbrOfConversion = 1;
    hadc1.Init.ScanConvMode = ENABLE;
    hadc1.Init.ContinuousConvMode = DISABLE;
    hadc1.Init.DiscontinuousConvMode = ENABLE;
    HAL_ADC_Init(&hadc1);
	
	  //int GLCD and touch screen 
	  GLCD_Initialize();
    Touch_Initialize();
	
	  HAL_Init();

    //initializing the system clock, channel and the GPIO for Water Sensor
    water_Config();
    //initializing the relay
	  relay_init();
	  //initializing the buzzer
	  buzzer_init();
	  //set the background of the GLCD screen to white
	  backgroundColor();
	  //displaying the home page at the start
    homePage();
		//init LED
		led_GPIO_Init();
		//init button
		button_GPIO_Init();
	
    //main loop
   while(1) {
			
			int touchFlag;
		
			   TOUCH_STATE tsc_state;
		     
        //read ADC value
        uint16_t water_adc_read;
	      uint16_t button_val = 0;
         		
			//start ADC conversion
        HAL_ADC_Start(&hadc1);
			  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
        water_adc_read = HAL_ADC_GetValue(&hadc1);			
        
				//set a flag when the screen is touched
				Touch_GetState(&tsc_state);
				if (tsc_state.pressed) {					
						touchFlag = 1;
				  
				 }
				
				 //main water reading loop
				if (touchFlag == 1) {	
					   readingPage();		
					if (touchFlag == 1 && water_adc_read > 500) {
				 sprintf(msg,"Water pump is off");
				 GLCD_DrawString(20, 120,msg);
						sprintf(msg,"Water is detected");
          GLCD_DrawString(20, 80, msg);
           relay_off();
           buzzer_off();
           led_off();	
						
			 } else {
				 sprintf(msg, "Water pump is on");
				 GLCD_DrawString(20, 120,msg);
				 sprintf(msg, "Water is not detected");
          GLCD_DrawString(20, 80, msg);
				 relay_on();
				 buzzer_on();
				 led_on();
				 
			 }
			 //manual button loop
			 button_val = HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_6);
			 if (button_val == 0) {
				 relay_on();
				 led_on();
				 buzzer_on();
			 }
       			 
		}							         
			wait_delay(500);	
	}
	 
}