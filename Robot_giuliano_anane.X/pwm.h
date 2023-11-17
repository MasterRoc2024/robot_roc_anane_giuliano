/* 
 * File:   pwm.h
 * Author: GEII Robot
 *
 * Created on 3 octobre 2023, 09:50
 */ 

#ifndef PWM_H

#define	PWM_H

#define MOTEUR_GAUCHE 48
#define MOTEUR_DROIT 25

void InitPWM(void); 
void PWMSetSpeed(float vitesseEnPourcents, unsigned char motorNb);
void PWMUpdateSpeed();
#endif /* TIMER_H */