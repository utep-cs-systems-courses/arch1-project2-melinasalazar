
#include <msp430.h>
#include "timer.h"
#include "state_machine.h"

static unsigned int random = 0;
static unsigned short start_time = 0;
static unsigned short current_time = 0;
static unsigned short state_time = 0;
static unsigned short state_transition = 0;

void timer_start(){
  start_time = current_time;// Set current time to start time
}

unsigned short timer_elapsed(){
  random += current_time % 5;
  return current_time - start_time;// elapsed time
}

void __interrupt_vec(WDT_VECTOR) WDT(){ // WDT Interrupt
  state_time++;
  current_time++;
  random++;

  if(state_time >= state_transition){
    state_time = 0;
    random += 5;
    state_update();
    
 }


}
   
  void timer_set_transition(unsigned short delay){
  state_transition = delay;
}

unsigned int rand() {
  return M * random + I;    // Generate the next state of the LCG
}
