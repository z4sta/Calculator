#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Operations.h"

char GetOperatorFromInput();
void GetInput(float* dInput, char* strMsg);



int main()
{

	// Define varriables
	bool bContinue = true;

	char cOperator;
	float dFirstInput = 0;
	float dSecondaryinput = 0;
	float* pTest = NULL; // Example of bad pointer

	do {

		// Gather all inputs
		cOperator = GetOperatorFromInput();
		GetInput(&dFirstInput, "First Number");
		GetInput(&dSecondaryinput, "Second Number");

		GetInput(pTest, "Third Number"); // Example of bad pointer

	
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

		switch (cOperator) {
		case '/':
		case '*':
		case '-':
		case '+':
			bValidInput = true;
			break;
		default:
			printf("invalid operator\n\n");
			bValidInput = false;
		};


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
