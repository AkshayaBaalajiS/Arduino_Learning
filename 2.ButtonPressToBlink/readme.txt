setUp:  is a function where the pin mode is set to either input or output
pinMode: is a function to set the pin to either input or output

loop: is a function to continuously run the code in board 
digitalWrite: is a function to make a pin in the board to high or low 

sleep: is a function to make the program sleep in seconds 
delay: is a function to make the program to sleep in milliseconds 

by setting a pin to INPUT_PULLUP
you are telling the ESP32 (or Arduino) to:
Treat the pin as an input.
Activate an internal pull-up resistor (~45kΩ).
You enabled INPUT_PULLUP, so the button reads:
	HIGH when not pressed.
	LOW when pressed.