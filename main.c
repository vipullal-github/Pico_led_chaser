#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"
#include "hardware/clocks.h"



// Define a pinArray for the tri-color LED's. The first number gives the anode of the 
// red LED, the next the green LED and the last is the blue LED.
const uint pinArray[] = { 
	14,15,12,		// set 1
	4,5,6,		    // set 2
	0,1,2,			// set 3
};

const uint max_led_count = sizeof(pinArray)/sizeof(uint);

// ----------------------------------------
void togglePin( uint pin ){
    uint onOff = gpio_get( pin );
    onOff = onOff + 1;
    onOff &= 0x01;
    gpio_put( pin, onOff );
}


// ----------------------------------------
void flashPin( uint pin ){
	togglePin(pin);
	sleep_ms(500);
	togglePin(pin);
	sleep_ms(500);
}

#define COUNT_UP 1
#define COUNT_DOWN 0
#define MAX_SLEEP_TIME 350
#define MIN_SLEEP_TIME 20


// -------------------------------------------
int main(){

    stdio_init_all();
    gpio_init( PICO_DEFAULT_LED_PIN);
    gpio_set_dir( PICO_DEFAULT_LED_PIN, GPIO_OUT);

    // Initialize all the ports. 
	for(uint i = 0; i < max_led_count; i++){
		gpio_init( pinArray[i] );
		gpio_set_dir( pinArray[i], GPIO_OUT );
	}
	
	uint sleepTime = 250;
	uint direction = COUNT_DOWN;
	
    while (1){
		uint i;
		for( i = 0; i < 3; i++ ){
			uint pin1 = pinArray[ 0 + i ];
			uint pin2 = pinArray[ 3 + i ];
			uint pin3 = pinArray[ 6 + i ];
			
			printf("\nToggleing %d %d %d", pin1, pin2, pin3 );
			gpio_put( pin1, 1);
			sleep_ms(sleepTime);
			gpio_put( pin1, 0);
			gpio_put( pin2, 1);
			sleep_ms(sleepTime);
			gpio_put( pin2, 0);
			gpio_put( pin3, 1);
			sleep_ms(sleepTime);
			gpio_put( pin3, 0);
			if( direction == COUNT_UP ){
				sleepTime += 20;
				if( sleepTime >= MAX_SLEEP_TIME ){
					direction = COUNT_DOWN;
				}
			}
			else{
				sleepTime -= 20;
				if( sleepTime <= MIN_SLEEP_TIME ){
					direction = COUNT_UP;
				}
			}
		}
		
    }

    return 0;

}


