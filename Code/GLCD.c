#include <stdio.h>
#include "stm32f7xx_hal.h"
#include "GLCD_Config.h"
#include "Board_GLCD.h"
#include "Board_Touch.h"
#include "GLCD.h"
extern GLCD_FONT GLCD_Font_16x24;



void backgroundColor (void) {
	GLCD_Initialize();
  Touch_Initialize();
  GLCD_SetBackgroundColor(GLCD_COLOR_WHITE); 
}
void homePage() {
	
	GLCD_Initialize();
  Touch_Initialize();
	GLCD_ClearScreen();
	
	GLCD_SetFont(&GLCD_Font_16x24);
  GLCD_SetForegroundColor(GLCD_COLOR_BLACK);
	GLCD_DrawString(175, 80, "Welcome");
	GLCD_DrawString(210,110, "to");
	GLCD_DrawString(80, 140,"Nano Auto Hydrophonic");
	GLCD_DrawString(130, 180, "Press to Start");
}

void readingPage (void) {
	
	GLCD_Initialize();
	Touch_Initialize();
	GLCD_ClearScreen();
	
	GLCD_SetFont(&GLCD_Font_16x24);
  GLCD_SetForegroundColor(GLCD_COLOR_BLACK);
	
	
}