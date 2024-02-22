#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Operations.h"

#define VERSION_NUMBER 1.5

bool IsValidOperator(char* cOperator);
void CalculateResult(float* dFirstInput, char* cOperator, float* dSecondInput);
char GetOperatorFromInput();
void GetInput(float* dInput, char* strMsg);


int main()
{

	// Define variables
	float fFirstNumber = 0;
	float fSecondNumber = 0;
	char cOperator[2]; // Considering operator will be a single character
	bool bContinue = true;
	bool bFirst = true;

	//TODO: add header print (ASCII ART + Programm name + version + F1: help)
	//TODO: presing f1 prints help
	//TODO: stop/exit for stop (close)
	//TODO: clear for clearing console / restarting (write header again)

	printf("Version: %.1f", VERSION_NUMBER);
	printf("\n");

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
		printf("%f %c %f = %f\n", *dFirstInput, *cOperator, *dSecondInput, Divide(*dFirstInput, *dSecondInput));
		break;
	case '*':
		printf("%f %c %f = %f\n", *dFirstInput, *cOperator, *dSecondInput, Multiply(*dFirstInput, *dSecondInput));
		break;
	case '-':
		printf("%f %c %f = %f\n", *dFirstInput, *cOperator, *dSecondInput, Subtract(*dFirstInput, *dSecondInput));
		break;
	case '+':
		// %.2f == 2 comma only
		printf("%f %c %f = %f\n", *dFirstInput, *cOperator, *dSecondInput, Add(*dFirstInput, *dSecondInput));
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
