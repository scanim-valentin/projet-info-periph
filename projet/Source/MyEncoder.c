#include "Driver_GPIO.h"
#include "MyTimer.h"
#include "stm32f10x.h"
#include "MyEncoder.h"

void MyEncoder_Init(MyEncoder_Struct_TypeDef * struct_Encoder) {
	
	// On setup les ARR et PSC des deux compteurs A et B en format timer. Un seul timer n�cessaire.
	MyTimer_Base_Init(struct_Encoder->struct_compteur_AB);
	
	//////// RM 391 Encoder Interface ////////
	struct_Encoder->struct_compteur_AB->Timer->SMCR = TIM_SMCR_SMS_1; // peut aussi choisir 0 et 1.
	// on compte les transitions de TI1 et TI2 donc on choisit le mode 2.
	// input filter ? polarity selection ?
	// TI1 et TI2 c'est les deux input filter qui sont compt�s par le Encoder mode. Correspondent aux TIMx_CH1 et TIMx_CH2 (RM 425).
	
	// Il faut enable le TIMER (bit CEN dans CR1)
	MyTimer_Base_Init(struct_Encoder->struct_compteur_AB);
	
	// Partie External Interrupt pour reset le counter
	// Fait avec un seul pin et un seul gpio. On se d�cide et on le garde, pas possible de faire un switch (trop de cas).
	
	
	// "Configure the mask bits of the 20 Interrupt lines" (RM 207)
	EXTI->IMR = EXTI_IMR_MR4; //"Interrupt Mask on line 1" pas sur que c'est ce qu'il faut faire (je sais pas ce ue �a fait mais c'est logique).
	//EXTI->EMR = EXTI_EMR_MR2; //"Interrupt Mask on line 1" pas sur que c'est ce qu'il faut faire (je sais pas ce ue �a fait mais c'est logique).
	
	//2 -> 4
	// on configure dans quels cas ya l'interruption, ici quand ya un front montant ou descendant
	EXTI->RTSR = EXTI_RTSR_TR4; // �a veut dire "si pin 1 a un "R"ising alors on trigger l'external interrupt 1
	EXTI->FTSR = EXTI_FTSR_TR4; // �a veut dire "si pin 1 a un "F"alling alors on trigger l'external interrupt 1
	
	// il faut encore d�clarer la fonction "EXTI1_IRQHandler" au NVIC sinon �a va pas marcher
	// En RM �a veut dire "Configure the enable and mask bits that control the NVIC IRQ channel mapped to the External Interrupt Controller
	// so that an interrupt comming from the 20 lines can be properly acknowledged"
	NVIC_EnableIRQ(EXTI4_IRQn);
	
	
	
}

short MyEncoder_getPosition(MyEncoder_Struct_TypeDef * struct_encoder) {
	return struct_encoder->struct_compteur_AB->Timer->CNT;
}


void EXTI4_IRQHandler(void) {
	TIM2->CNT = 0; //reset counter
	EXTI->PR |= ~(EXTI_PR_PR4); // release interrupt
}

