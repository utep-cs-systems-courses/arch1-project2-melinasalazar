
#ifndef buttons_included
#define buttons_included

#define BOTTOM BIT3 // p1.3
#define BOTTOM_SWITCHES BOTTOM

#define TOP_1 BIT0 // p2.0
#define TOP_2 BIT1 // p2.1
#define TOP_3 BIT2 // p2.2
#define TOP_4 BIT3 // p2.3
#define TOP_SWITCHES (TOP_1 | TOP_2 | TOP_3 | TOP_4)

void button_init();
void switch_interrupt_handler();

extern char bottom;
extern char top_1;
extern char top_2;
extern char top_3;
extern char top_4;

#endif //end  buttons_included
