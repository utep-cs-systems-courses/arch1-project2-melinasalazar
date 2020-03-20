
#include <msp430.h>
#include "led.h"
#include "buzzer.h"
#include "timer.h"

static int song[] = {E7, E7, 0, E7, 0, C7, E7, 0, G7, 0, 0,  0, G6, 0, 0, 0, C7, 0, 0, G6, 0, 0, E6, 0, 0, A6, 0, B6, 0, AS6, A6, 0, G6, E7, G7, A7, 0, F7, G7, 0, E7, 0, C7, D7, B6, 0, 0, C7, 0, 0, G6, 0, 0, E6, 0, 0, A6, 0, B6, 0, AS6, A6, 0, G6, E7, G7, A7, 0, F7, G7, 0, E7, 0, C7,  D7, B6, 0, 0, 0 , -1 };

static int song_pace[] = { 12, 12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6, 3,  12, 12, 12, 12, 12, 12, 6, 6, 18, 18, 18, 6, 6, 6, 6, 6, 6, 18, 18, 18, 18, 18, 18, 10, 10, 10,  10, 10, 10, 3, 3, 3 };


static unsigned short duration = 250; // 250 ms
static unsigned short current_note = 0;
static unsigned short tot_duration = 0; // total duration

char buzzer_state = 0;

void buzzer_init(){ // Inititalize speaker and buzzer method

  timerAUpmode();/* used to drive speaker */

  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7; 
  P2SEL |= BIT6;
  P2DIR |= BIT6;/* enable output to speaker (P2.6) */

  tot_duration = (int)(duration / song_pace[0]);
  buzzer_state = BUZZER_OFF;
  current_note = 0;

}

void buzzer_set_period(short cycles){ 
  CCR0 = cycles; 
  CCR1 = cycles >> 1;/* one half cycle */
}



void buzzer_play(){
  
  buzzer_state = BUZZER_ON;// buzzer is playing set the state

  int note = song[current_note];// set current note to song

  
  if(note < 0){// if song ends
    buzzer_state = BUZZER_OFF;
    current_note = 0;
    return;
}

  
  if(note == 0){
    led_state(1, 0);// RED LED on when song off
}

  
  else{
    led_state(0, 1);// GREEN LED on when song on
}

  buzzer_set_period(note);// play current note
  
  
 tot_duration--;// decrement duration

 
  if(tot_duration <= 1){//check if end of note
    current_note++;// next note
    tot_duration = (int)(duration / song_pace[current_note]);//update song timing
   }  
}
