# Pico_led_chaser
Project to build an LED chaser with the Raspberry PI PICO

![image](IMG_20210805_130053.jpg)


(PS: That orange wire sticking out from the right side of the board is what I use to reset the PICO. It's not part of the main circute)


You will need:

1. At least 3 tri-color LED's. You can use single color LED's, but you will have to change the circute accordingly.
2. Three 470 or thereabouts resistors to keep the current through the LED and your controller within limits.
3. A PICO micro controller
4. A solderless breadboard
5. Some jumper wires.
6. A computer to write, edit and upload the .elf file generated. 

I used the Linux subsystem on my Windows 10 laptop to compile the code. You can refer to the excellent PICO setup guide on how to setup your environment.

If you have buld issues, please make sure your "pico_sdk_import.cmake" is the correct one.

To begin, wire up the three color LED's to GPIO pins. Since we use only one color at a time, we can get by with only one resistor with each LED. 

You can connect the LED's to any free GPIO pin you like. You will need to change the pinArray accordingly. In my case, I have used GPIO pins 14, 15 and 12 to the R-G-B of the firse LED. Similarly, I have used pins 4,5,6 for the second LED. You can use a different arrangement; R-R-R of the three LED's, followed by G-G-G of the three LED's and so on. It's a matter of choice.  

The code itself is pretty simple.

To build the .uf2 file:

1.  mkdir build && cd build
2.  cmake ../
3.  make


