#ifndef MYTIMER_H
#define MYTIMER_H

#include "stm32f10x.h"

#define TIMxCLK 72000000

typedef struct
{
	TIM_TypeDef * Timer ; // TIM1 � TIM4
	unsigned short ARR ;
	unsigned short PSC ;
} MyTimer_Struct_TypeDef ;


/*
*****************************************************************************************
* @brief
* @param -> Param�tre sous forme d�une structure (son adresse) contenant les informations de base
* @Note -> Fonction � lancer syst�matiquement avant d�aller plus en d�tail dans lesconf plus fines (PWM, codeur inc ... )
*************************************************************************************************
*/

void MyTimer_Base_Init (MyTimer_Struct_TypeDef * Timer) ;

#define MyTimer_Base_Start(TimerStruct) (TimerStruct->Timer->CR1 |= (0x01))
#define MyTimer_Base_Stop(TimerStruct) (TimerStruct->Timer->CR1 |= (0x00))

/*
**************************************************************************************************
* @brief
* @param : - TIM_TypeDef * Timer : Timer concerne
- char Prio : de 0 a 15
* @Note : La fonction MyTimer_Base_Init doit avoir ete lancee au prealable
Page 2 of 4
Activit� 2 : Utilisation des Timer et gestion des Interruptions
**************************************************************************************************
*/
void MyTimer_ActiveIT (TIM_TypeDef * Timer , char Prio, void (*IT_function) (void)) ;

/**
* @brief
* @param ....
* @Note Active le channel sp�cifi� sur le timer sp�cifi�
* la gestion de la configuration I/O n�est pas faite dans cette fonction
* ni le r�glage de la p�riode de la PWM (ARR, PSC)
*/
void MyTimer_PWM (TIM_TypeDef * Timer, char Channel) ;

void Rapport_Cyclique (TIM_TypeDef * Timer, uint32_t Impul, char Channel) ;

#endif
