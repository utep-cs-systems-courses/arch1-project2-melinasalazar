
#include <msp430.h>
#include "led.h"
#include "buttons.h"

void led_init(){
  P1DIR |= LEDS;// Initialize led
}

int led_state(int red_state, int green_state){
  if(red_state < 0 || red_state > 1 || green_state < 0 || red_state > 1)
    return 0;
  
  char ledFlags = 0;

  ledFlags |= red_state ? LED_RED : 0;
  ledFlags |= green_state ? LED_GREEN : 0;

  P1OUT &= (0xff - LEDS) | ledFlags;// Clear bits off led 
  P1OUT |= ledFlags; // set bits on led
  
 
}

