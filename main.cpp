#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    DigitalIn gasDetector(D2); 
    /*
    voy al constructor de digitalin y usa gpio
    https://os.mbed.com/docs/mbed-os/v6.15/mbed-os-api-doxy/gpio__api_8h_source.html
*/
    gasDetector=gpio_init_in(&gpio, D2); //no se de donde saca gpio pero gpio CREO es un objeto
    // en fin esto deberia inicializar el pin D2 


    DigitalOut alarmLed(LED1);

    gasDetector.mode(PullDown);

    alarmLed = OFF;

    while (true) {
        if ( gasDetector == ON ) {
            alarmLed = ON;
        }
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;
        }
    }
}