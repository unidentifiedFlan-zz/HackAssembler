//Convert input number to 16-bit binary number, assuming array to whihc binary is stored has already been initialised
//as an array of zeroes.

#include "stdafx.h"
#include "convertToBinary.h"

int convertToBinary(char binaryNum[], int num) {

	if (!num)
		return 0;

	int bitCnt = 0;
	int number = num;

	while (number > 0) {

		while (!(number % 2)) {
			bitCnt++;
			number /= 2;
		}

		number--;
	}

	binaryNum[15 - bitCnt] = '1';

	//Find the closest power of 2, less than num, and subtract it from num. Repeat above process for remainder.
	if (bitCnt > 0) {
		int closestBin = 1;
		for (int i = 1; i <= bitCnt; i++)
			closestBin *= 2;

		number = num - closestBin;
	}

	convertToBinary(binaryNum, number);

	return 1;
}
