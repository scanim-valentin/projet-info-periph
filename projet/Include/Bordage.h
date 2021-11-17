#ifndef BORDAGE_H
#define BORDAGE_H

#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"
#include "Driver_Servo.h"
#include "MyEncoder.h"


void Bordage_Init(MyTimer_Struct_TypeDef * timer, MyGPIO_Struct_TypeDef * pin_servo, char channel_pwm, MyEncoder_Struct_TypeDef * encoder);

void Handler_Bordage(void);

#endif
