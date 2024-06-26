/* 
 * File:   CB_RX1.h
 * Author: GEII Robot
 *
 * Created on 16 avril 2024, 11:09
 */

#ifndef CB_RX1_H
#define	CB_RX1_H

void CB_RX1_Add(unsigned char value);
unsigned char CB_RX1_Get(void);
unsigned char CB_RX1_IsDataAvailable(void);
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void);
int CB_RX1_GetDataSize(void);
int CB_RX1_GetRemainingSize(void);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CB_RX1_H */

