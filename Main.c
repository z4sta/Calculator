#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "Operations.h"

#define VERSION_NUMBER 1.5
#define HELP_KEY "help"
#define CLEAR_KEY "clear"
#define STOP_KEY "stop"
#define EXIT_KEY "exit"

// Validation
bool IsValidOperator(char* cOperator);
char GetOperatorFromInput();
void GetInput(float* dInput, char* strMsg);
bool DetermineAction();

// Calculations
void CalculateResult(float* dFirstInput, char* cOperator, float* dSecondInput);

// Misc
void PrintHeader();
void ClearConsole();
void PrintHelp();

// Main

//TODO: history (ans + stuff)

int main()
{

	PrintHeader();

	// Define variables
	float fFirstNumber = 0;
	float fSecondNumber = 0;
	char cOperator[2]; // Considering operator will be a single character
	bool bContinue = true;
	bool bFirst = true;

	

	// Main Loop
	do {
		
		if (!bFirst) {
			printf("\n");
		}
		bFirst = false;

		printf("cmd: ");
		if (scanf_s("%f %1s %f", &fFirstNumber, cOperator, sizeof(cOperator), &fSecondNumber) == 3) {

			if (!IsValidOperator(cOperator)) {
				printf("Operator not valid\n");
				continue;
			}

			CalculateResult(&fFirstNumber, &cOperator, &fSecondNumber);

		}
		else {
			if (DetermineAction() == 0) {return 0;}
		}

		int c;
		while ((c = getchar()) != '\n' && c != EOF);

	} while (bContinue);

	return 0;

}
bool DetermineAction()
{
	char temporary[100];
	scanf_s("%s", temporary, sizeof(temporary));

	if (strcmp(temporary, CLEAR_KEY) == 0) {
		ClearConsole();
	}
	else if (strcmp(temporary, STOP_KEY) == 0) {
		return 0;
	}
	else if (strcmp(temporary, EXIT_KEY) == 0) {
		return 0;
	}
	else if (strcmp(temporary, HELP_KEY) == 0) {
		PrintHelp();
	}
	else {
		printf("Invalid input\n");
	}

}


void PrintHelp() {
	ClearConsole();

	printf("\x1b[95m"); // Set text color to pink
	printf("\x1b[91m\x1b[1m"); // Set text color to red and make it bold
	printf("-- DOCUMENTATION --\n\n");
	printf("\x1b[95m"); // Set text color back to pink
	printf("\x1b[34m\x1b[1m"); // Set text color to blue and make it bold
	printf("# USAGE\n\n");
	printf("\x1b[95m"); // Set text color back to pink
	printf("- clear . . . . . . . : clears console\n");
	printf("- exit  . . . . . . . : exits the application\n");
	printf("- stop  . . . . . . . : exits the application\n");
	printf("- help  . . . . . . . : prints out the documentation\n\n");
	printf("e.g: (number) (operator) (number) --> 20 + 20\n\n");
	printf("operators: + , - , * , /\n\n");
	printf("\x1b[34m\x1b[1m"); // Set text color back to blue and make it bold
	printf("# CREDITS\n\n");
	printf("\x1b[95m"); // Set text color back to pink
	printf("written in c\n");
	printf("by @z4sta on github\n\n");
	printf("\x1b[91m\x1b[1m"); // Set text color to red and make it bold
	printf("-- END OF DOCUMENTATION --\n");
	printf("\x1b[0m"); // Reset text color to default

}

void ClearConsole() {
	system("cls");
	PrintHeader();
}

void PrintHeader() {

	printf("\x1b[33m ______     ______     __         ______     __  __     __         ______     ______   ______     ______    \n");
	printf("/\\  ___\\   /\\  __ \\   /\\ \\       /\\  ___\\   /\\ \\/\\ \\   /\\ \\       /\\  __ \\   /\\__  _\\ /\\  __ \\   /\\  == \\   \n");
	printf("\\ \\ \\____  \\ \\  __ \\  \\ \\ \\____  \\ \\ \\____  \\ \\ \\_\\ \\  \\ \\ \\____  \\ \\  __ \\  \\/_/\\ \\/ \\ \\ \\/\\ \\  \\ \\  __<   \n");
	printf(" \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\_\\    \\ \\_\\  \\ \\_____\\  \\ \\_\\ \\_\\ \n");
	printf("  \\/_____/   \\/_/\\/_/   \\/_____/   \\/_____/   \\/_____/   \\/_____/   \\/_/\\/_/     \\/_/   \\/_____/   \\/_/ /_/ \n\n");

	printf("VERSION: %.1f\n", VERSION_NUMBER);
	printf("TYPE IN '%s' for documentation", HELP_KEY);
	printf("\n\n");

	printf("\x1b[0m"); // Reset color to default

}

bool IsValidOperator(char* cOperator) {
	switch (*cOperator) {
	case '/':
	case '*':
	case '-':
	case '+':
		return true;
		break;
	default:
		return false;
	};
}

void CalculateResult(float* dFirstInput, char* cOperator, float* dSecondInput) {
	if (!dFirstInput || !cOperator || !dSecondInput) {
		printf("null pointer exepction");
		return;
	}
	
	switch (*cOperator) {
    case '/':
        printf("%f %c %f = \x1b[32m%f\x1b[0m\n", *dFirstInput, *cOperator, *dSecondInput, Divide(*dFirstInput, *dSecondInput));
        break;
    case '*':
        printf("%f %c %f = \x1b[32m%f\x1b[0m\n", *dFirstInput, *cOperator, *dSecondInput, Multiply(*dFirstInput, *dSecondInput));
        break;
    case '-':
        printf("%f %c %f = \x1b[32m%f\x1b[0m\n", *dFirstInput, *cOperator, *dSecondInput, Subtract(*dFirstInput, *dSecondInput));
        break;
		// %.2f == 2 comma only
	case '+':
		printf("%f %c %f = \x1b[32m%f\x1b[0m\n", *dFirstInput, *cOperator, *dSecondInput, Add(*dFirstInput, *dSecondInput));
		break;
	default:
		printf("invalid operator\n");
		break; 
	}

}

char GetOperatorFromInput()
{

	char cOperator;
	bool bValidInput = true;

	do {

		printf("Operator: ");
		scanf_s("%c", &cOperator);

		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		
		bValidInput = IsValidOperator(cOperator);

	} while (!bValidInput);

	return cOperator;
}

void GetInput(float* dInput, char* strMsg) {
	if(!dInput || !strMsg){
		return; //Errorhandling
	}


	bool bValidInput = true;

	do {

		printf("%s : ", strMsg);

		if (scanf_s("%f", dInput) != 1) {
			bValidInput = false;
		}
		else
		{
			bValidInput = true;
		}

		int c;
		while ((c = getchar()) != '\n' && c != EOF);


	} while (!bValidInput);
}
