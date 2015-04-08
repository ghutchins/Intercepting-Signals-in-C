
NAME:Georgina Hutchins

CSC-241 - Lab 1





	The C program lab1_Hutchins.c repeatedly prompts the user to input a username,
	but only allows for input within a predetermined period of time. It then responds 
	based on the input, or notifies the user that the timer has expired before reprompting.
	With the use of signal handling, the program sets a timeout value of 5 seconds for the
	user to enter their username before reprompting. If the input is the word "exit," the
	program is killed and exits immediately.An interrupt handler catches the ^C signal, and
	instead displays a message to the user.

	

The signal handler function "alarmHandler" is invoked when the user does not respond
	within the allotted. time. The function "quitHandler" is an interrupt handler that
	catches ^C (SIGINT) from the terminal or other processes. 

	

In the event that the program needs to be killed, the PID is 28438.
	

	






Program compiled using gcc -Wall -o executable lab1_Hutchins.c


