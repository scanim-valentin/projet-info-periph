#include "MyGPIO.h"
#include "MyTimer.h"
#include "stm32f10x.h"
#include "stm32f10x_exti.h"

typedef struct{
	MyGPIO_Struct_TypeDef * Girouette_I; // linked to external interrupt output and triggers counter reset RM 206
	MyTimer_Struct_TypeDef * struct_compteur_AB;
} MyGirouette_Struct_TypeDef;
/*
typedef struct {
	TIM_TypeDef * Timer; // TIM1 à TIM4
	unsigned short ARR;
	unsigned short PSC;
} MyTimer_Struct_TypeDef;

typedef struct{
	GPIO_TypeDef * GPIO ;
	char GPIO_Pin ; //numero de 0 à 15
	char GPIO_Conf ; // voir ci-dessous
} MyGPIO_Struct_TypeDef;

typedef struct
{
  __IO uint32_t IMR;
  __IO uint32_t EMR;
  __IO uint32_t RTSR;
  __IO uint32_t FTSR;
  __IO uint32_t SWIER;
  __IO uint32_t PR;
} EXTI_TypeDef;*/

//Initiating timer and GPIO
void MyEncoder_Init(MyGirouette_Struct_TypeDef * struct_encoder);

//Returns the encoder's timer counter
unsigned short MyEncoder_getPosition(MyGirouette_Struct_TypeDef * struct_encoder);


