/**
 * @file Modules.ino
 * @brief 
 * @author Yuki HONMA @ ProjectR
 * @date 2019/10/20
 */


#include <arduino.h>

#include "Sakura_modules.h"

#define PIN_CONT_X A0
#define PIN_CONT_Y A1
#define PIN_CONT_T A2

#define CONT_SPEED 1.0
#define CONT_ANG 3.14

#define BUFF_SMOOTH 50


S_UnderBody Omni4(&Serial1);

void setup(){

    pinMode(PIN_LED0, OUTPUT);
    analogReference(RAW12BIT);

    digitalWrite(PIN_LED0, HIGH);
    Omni4.begin(115200);
}

void loop(){

    static double vX[BUFF_SMOOTH + 1] = {}, vY[BUFF_SMOOTH + 1] = {}, omega[BUFF_SMOOTH + 1] = {};
    double sumVX = 0, sumVY = 0, sumOmega = 0;

    vX[0] = ((double)analogRead(PIN_CONT_X) - 2048.0)*CONT_SPEED / 4096.0;
    vY[0] = ((double)analogRead(PIN_CONT_Y) - 2048.0)*CONT_SPEED / 4096.0;
    omega[0] = ((double)analogRead(PIN_CONT_T) - 2048.0)*CONT_ANG / 4096.0;

    for(int i=BUFF_SMOOTH; i>0; i--){
        vX[i] = vX[i-1];
        vY[i] = vY[i-1];
        omega[i] = omega[i-1];

        sumVX += vX[i];
        sumVY += vY[i];
        sumOmega += omega[i];
    }

    Omni4.moveXY(sumVX/(double)BUFF_SMOOTH, sumVY/(double)BUFF_SMOOTH, sumOmega/ (double)BUFF_SMOOTH);

    delay(10);
}