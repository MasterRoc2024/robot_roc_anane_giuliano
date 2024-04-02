#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "PWM.h"
#include "ADC.h"
#include "Robot.h"
#include "UART.h"
#include "CB_TX1.h"
//int ADCValue0;
//int ADCValue1;
//int ADCValue2;

int main(void) {
    /***************************************************************************************************/
    //Initialisation de l?oscillateur
    /****************************************************************************************************/
    InitOscillator();
    /****************************************************************************************************/
    // Configuration des éentres sorties
    /****************************************************************************************************/
    InitIO();
    InitTimer23();
    InitTimer1();
    InitPWM();
    InitADC1();
    InitUART(); 
    

    /****************************************************************************************************/
    // Boucle Principale
    /****************************************************************************************************/
    while (1) {
        SendMessageDirect((unsigned char*) "Bonjour", 7);
        //__delay32(40000000);
        if (ADCIsConversionFinished() == 1)
        {
            ADCClearConversionFinishedFlag();
            unsigned int * result = ADCGetResult();
            float volts = ((float) result [2])* 3.3 / 4096 * 3.2;
            robotState.distanceTelemetreDroit = 34 / volts - 5;
            volts = ((float) result [1])* 3.3 / 4096 * 3.2;
            robotState.distanceTelemetreCentre = 34 / volts - 5;
            volts = ((float) result [0])* 3.3 / 4096 * 3.2;
            robotState.distanceTelemetreGauche = 34 / volts - 5;

            
            if (robotState.distanceTelemetreDroit < 30)
            {
                LED_BLANCHE = 1;  
            }
            else 
            {
                LED_BLANCHE = 0;
            }
            if (robotState.distanceTelemetreGauche < 30)
            {
                LED_ORANGE = 1;  
            }
            else 
            {
                LED_ORANGE = 0;
            }
            if (robotState.distanceTelemetreCentre < 30)
            {
                LED_BLEUE = 1;  
            }
            else 
            {
                LED_BLEUE = 0;
            }
        }
    }
} // fin main
