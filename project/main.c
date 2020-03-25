
#include <msp430.h>
#include "state_machine.h"
#include "led.h"
#include "buttons.h"
#include "buzzer.h"
#include "timer.h"

void main(void){

  configureClocks();// Timer setup

  button_init(); // start buttons

  buzzer_init(); // start song

  led_init();// Initialize led
  led_state(1,1);

  enableWDTInterrupts(); // interrupts

  or_sr(0x18);  // CPU off, GIE on
} 
