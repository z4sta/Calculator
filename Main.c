#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Operations.h"

void functionA(int i);

int main()
{

	bool bValidInput = true;
	bool bContinue = true;

	char cOperator;
	float dFirstInput = 0;
	float dSecondaryinput = 0;

	do {

		bValidInput = true;

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
				printf("invalid operator\n");
				bValidInput = false;
			};


		} while (!bValidInput);

		bValidInput = true;

		do {

			printf("First Number: ");

			if (scanf_s("%f", &dFirstInput) != 1) {
				bValidInput = false;
			}
			else
			{
				bValidInput = true;
			}

			int c;
			while ((c = getchar()) != '\n' && c != EOF);


		} while (!bValidInput);

		bValidInput = true;

		do {

			printf("Second Number: ");

			if (scanf_s("%f", &dSecondaryinput) != 1) {
				bValidInput = false;
			}
			else
			{
				bValidInput = true;
			}

			int c;
			while ((c = getchar()) != '\n' && c != EOF);


		} while (!bValidInput);
	
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



	//system("cls");
} 

void functionA(int i)
{
	return;
}
