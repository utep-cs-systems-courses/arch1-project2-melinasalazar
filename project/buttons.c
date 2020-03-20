
#include <msp430.h>
#include "buttons.h"
#include "led.h"
#include "buzzer.h"

char bottom; // bottom switch 
char top_1; // starts from left first switch
char top_2; // second switch
char top_3; // third switch
char top_4; // fourth switch

void __interrupt_vec(PORT1_VECTOR) Port_1(){ // Interrupt for port 1 bottom switches
  if (P1IFG & BOTTOM_SWITCHES) { // set port1 bottom 
    P1IFG &= ~BOTTOM_SWITCHES; // set bits
    switch_interrupt_handler(); // call handler
  }
}



void __interrupt_vec(PORT2_VECTOR) Port_2(){ // Interrupt for port 2 top switches
  if (P2IFG & TOP_SWITCHES) { // set port 2 top
    P2IFG &= ~TOP_SWITCHES;// set bits
    switch_interrupt_handler();// call handler
  }
}

int switch_update_interrupt_sense_p1(){// Interrupt for bottom switch pressed
  char p1val = P1IN;

  P1IES |= (p1val & BOTTOM_SWITCHES);// switch up 
  P1IES &= (p1val | ~BOTTOM_SWITCHES);// switch down

  return p1val;
}


int switch_update_interrupt_sense_p2(){// Interrupt for top switches pressed
  char p2val = P2IN;

  P2IES |= (p2val & TOP_SWITCHES);// switch up
  P2IES &= (p2val | ~TOP_SWITCHES);// switch down/

  return p2val;
}

void button_init()//Initialize switches method
{ 
  // Set-up bottom switches
  P1REN |= BOTTOM_SWITCHES;// enables resistors  
  P1IE |= BOTTOM_SWITCHES;// enable interrupts
  P1OUT |= BOTTOM_SWITCHES;// pull-ups 
  P1DIR |= ~BOTTOM_SWITCHES;// set bits

  switch_update_interrupt_sense_p1();

  // Set-up top switches
  P2REN |= TOP_SWITCHES;// enables resistors
  P2IE |= TOP_SWITCHES;// enable interrupts
  P2OUT |= TOP_SWITCHES;// pull-ups 
  P2DIR &= ~TOP_SWITCHES;// set bits 

  switch_update_interrupt_sense_p2();

  switch_interrupt_handler();
}



void switch_interrupt_handler(){// Handler for switches

  // Bottom switches
  char p1val = switch_update_interrupt_sense_p1();
  bottom = (p1val & BOTTOM) ? 0 : 1;// Inititalize

  // Top switches
  char p2val = switch_update_interrupt_sense_p2();

  top_1 = (p2val & TOP_1) ? 0 : 1; /*Initialize*/
  top_2 = (p2val & TOP_2) ? 0 : 1;/*--------*/
  top_3 = (p2val & TOP_3) ? 0 : 1;/*---------*/
  top_4 = (p2val & TOP_4) ? 0 : 1;/*---------*/

}
