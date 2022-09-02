#include "mbed.h"
#include "arm_book_lib.h"

int main()
{

    DigitalIn gasDetector(D2);
    
    DigitalOut alarmLed(LED2);
    
    DigitalInOut buzzer(D3);
    buzzer.mode(OpenDrain);
    buzzer.input();    
    
    gasDetector.mode(PullDown);

    alarmLed=ON;
    while (true) {
            if (gasDetector.read() ==ON) { 
                buzzer.output();
                buzzer = LOW;
                alarmLed = ON;
                printf("led ON");
                ThisThread::sleep_for(500ms);
                alarmLed = OFF;
                buzzer.input();
                printf("led OFF");
                ThisThread::sleep_for(500ms);
            }
        
    }
}