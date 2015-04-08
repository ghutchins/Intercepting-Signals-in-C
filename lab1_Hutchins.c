
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef void (*sighandler_t)(int); 
sighandler_t signal(int signum, sighandler_t handler);

unsigned alarm(unsigned seconds);
void alarmHandler(int);
void quitHandler(int);


int main()
{	

	//get process id
	int pID = getpid();

	//deal with user input 
	char input[20];
	char exitString[20] = "exit";

	//set signal handlers
	signal (SIGALRM, alarmHandler);
	signal (SIGINT, quitHandler);	

	while(1)
	{
		printf("Type your username: ");
		fflush(stdout);
		alarm(5);

		if (scanf("%s", input))		
		{
			alarm(0);

			if (strcmp(input, exitString) == 0)
			{
				kill(pID, SIGKILL);	
			}

			printf("Your username is: %s\n", input);

		}

	}

	return 0;

}

void alarmHandler(int sAlarm)
{
	signal(SIGALRM, alarmHandler);


	printf("\n Time up! \n");
	printf("Type your username: ");
	fflush(stdout);
	alarm(5);		
	return;
}

void quitHandler(int sInt)
{
	signal(SIGINT, quitHandler); 
	
	printf("\n Please type 'exit' to quit. \n");
	printf("Type your username: ");
	fflush(stdout);
	alarm(5);
	return;
	
}


