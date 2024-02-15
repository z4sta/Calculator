#pragma once
#include "Operations.h"

float Subtract(float Minuend, float Subtrahend) {
	return Minuend - Subtrahend;
};

float Add(float BaseNumber, float Number) {
	return BaseNumber + Number;
}

float Divide(float BaseNumber, float Number) {
	return BaseNumber / Number;
}

float Multiply(float BaseNumber, float Number) {
	return BaseNumber * Number;
}
;

bool IsNumberEven(float BaseNumber) {

	if ((int)BaseNumber % 2 == 0) {
		return true;
	}

	return false;
	//return !(bool) (((int)BaseNumber) % 2);
}


