#ifndef MY_ADC
#define MY_ADC

#include "stm32f10x.h"

/*
	ADC12 PIN MAPPING ON STM32F103RB
	PC0
	PC1
	PC2
	PC3
*/

void MyADC_Init(ADC_TypeDef * ADC, char port, int pin);
void MyADC_ActiveIT( ADC_TypeDef * ADC, void (*IT_function) (void) ) ;
void MyADC_Start(ADC_TypeDef * ADC);
void MyADC_Stop(ADC_TypeDef * ADC);
int MyADC_Read(ADC_TypeDef * ADC);
#endif