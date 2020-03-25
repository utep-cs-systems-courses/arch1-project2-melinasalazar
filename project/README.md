## Blinky Buzzy Toys Computer Architecture Project 2

This program contains the following list of files:

Calls the initial clocks, interrupts, and classes that will start the program
* main.c

Enables the buzzer functions and programs the msp430 to perform buzzing sounds as well as a song
* buzzer.c, buzzer.h

Enables the led to work properly and turns the green and red respectively
* led.c, led.h

Controls the timer inturrepts and keeps track calling functions of the msp430
* timer.c, timer.h

Takes care of the switches by implementing the interrupts and activiting bottom and top switches
* button.c button.h

Takes care of the automata and changes of state machine in the program
* state_machine.c, state_machine.h

Compiles and loads the program into the msp430
* Makefile

The program starts playing musical notes and goes into a buzzer beep at the end of it. Green led indicates buzzer is playing, and
red led indicates a pressed on any of the switches. Furthermore, the user can skip the song by pressing any of the 4 top switches
or by pressing the bottom switch. When pressing any of the top 4 switches the user can later hear buzzing sounds from lower MHz to higher
MHz from the leftmost to rightmost switch respectively. Finally the user can press the bottom switch and see a nice animation of the 
red and green led switching between each other. 


To compile (Make sure to do this first on the demo folder to compile, then on as you would normally do on the project folder):
~~~
$ make
~~~
To run the program :
~~~
$ make load
~~~

To delete binaries:
~~~
$ make clean
~~~
