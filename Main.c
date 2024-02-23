#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Operations.h"

#define VERSION_NUMBER 1.5

// Validation
bool IsValidOperator(char* cOperator);
char GetOperatorFromInput();
void GetInput(float* dInput, char* strMsg);

// Calculations
void CalculateResult(float* dFirstInput, char* cOperator, float* dSecondInput);

// Misc
void PrintHeader();
void ClearConsole();

int main()
{

	PrintHeader();

	// Define variables
	float fFirstNumber = 0;
	float fSecondNumber = 0;
	char cOperator[2]; // Considering operator will be a single character
	bool bContinue = true;
	bool bFirst = true;

	//TODO: presing f1 prints help
	//TODO: stop/exit for stop (close)
	//TODO: clear for clearing console / restarting (write header again)

	// Main Loop
	do {
		
		if (!bFirst) {
			printf("\n");
		}
		bFirst = false;

		printf("Equation: ");
		if (scanf_s("%f %1s %f", &fFirstNumber, cOperator, sizeof(cOperator), &fSecondNumber) == 3) {

			if (!IsValidOperator(cOperator)) {
				printf("Operator not valid\n");
				continue;
			}

			CalculateResult(&fFirstNumber, &cOperator, &fSecondNumber);

		}
		else {
			printf("Error reading input\n");
		}

		int c;
		while ((c = getchar()) != '\n' && c != EOF);

	} while (bContinue);



	return 0;


	/*
	bool bContinue = true;
	char cOperator;
	float dFirstInput = 0;
	float dSecondaryinput = 0;
	*/
	/*
	do {

		// Gather all inputs
		cOperator = GetOperatorFromInput();
		GetInput(&dFirstInput, "First Number");
		GetInput(&dSecondaryinput, "Second Number");

		// Do operations based on operator given
		switch (cOperator) {
		case '/':
			printf("%f %c %f = %f\n", dFirstInput, cOperator, dSecondaryinput, Divide(dFirstInput, dSecondaryinput));
			break;
		case '*':
			printf("%f %c %f = %f\n", dFirstInput, cOperator, dSecondaryinput, Multiply(dFirstInput, dSecondaryinput));
			break;
		case '-':
			printf("%f %c %f = %f\n", dFirstInput, cOperator, dSecondaryinput, Subtract(dFirstInput, dSecondaryinput));
			break;
		case '+':
			// %.2f == 2 comma only
			printf("%f %c %f = %f\n", dFirstInput, cOperator, dSecondaryinput, Add(dFirstInput, dSecondaryinput));
			break;
		default:
			printf("invalid operator\n");
			break;
		}

		printf("\n");

	} while (bContinue);
	*/

	

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
	printf("PRESS F1 FOR HELP");
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
