/* 
 * File:   pwm.h
 * Author: GEII Robot
 *
 * Created on 3 octobre 2023, 09:50
 */ 

#ifndef PWM_H

#define	PWM_H

#define MOTEUR_DROIT 0
#define MOTEUR_GAUCHE 1

//void InitPWM(void);
//void PWMSetSpeed(float vitesseEnPourcents, int Motor);
void PWMSetSpeedConsigne(float vitesse, int moteur);
void PWMUpdateSpeed();
#endif /* TIMER_H */