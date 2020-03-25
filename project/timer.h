
#ifndef timer_included
#define timer_included

/* LCG constants */
#define M 49381 // Multiplier
#define I 8643 // Increment

void timer_start();
void timer_set_transition(unsigned short delay);

unsigned short timer_elapsed();
unsigned int rand();// LCG timer method set

void configureClocks();
void enableWDTInterrupts();
void timerAUpmode();
void or_sr (int or_val);

#endif // end timer_included
