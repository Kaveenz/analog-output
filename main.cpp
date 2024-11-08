#include "mbed.h"
#include "ThisThread.h"

AnalogIn ain(A1);
AnalogIn bin(A0);

PwmOut speaker(D6);

int main(){


    
                
    speaker.write(.5);
    speaker.period(1.0 / 500.0);


    while(1){


        float pMeterOne = ain.read();
        float pMeterTwo = bin.read();


        float freq = 500.0 + pMeterOne * (4000.0 - 500.0);
        float duty = pMeterTwo;

      
    
        speaker.period(1.0 / freq);
        speaker.write(duty);


        ThisThread::sleep_for(1000ms);
        
    }

}