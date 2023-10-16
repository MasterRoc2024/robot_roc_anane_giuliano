/* 
 * File:   toolbox.h
 * Author: GEII Robot
 *
 * Created on 3 octobre 2023, 09:40
 */

#ifndef TOOLBOX_H
#define	TOOLBOX_H
#define PI 3.141592653589793
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* TOOLBOX_H */

float Abs(float value);
float Max(float value, float value2);
float Min(float value, float value2);
float LimitToInterval(float value, float lowLimit, float highLimit);
float RadianToDegree(float value);
float DegreeToRadian(float value);