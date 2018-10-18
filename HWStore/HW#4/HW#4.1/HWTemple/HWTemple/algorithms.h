#pragma once

void decToTwosComplement(int number, int bitNumber[], const int numberLength);

int *addBitNumbers(const int bitNumber1[], const int bitNumber2[], const int lengthNumber);

int twosComplementToDec(int addResult[], const int addResultLength);

int calculateMaxLength(const int number1, const int number2);

void printBitNumber(int *bitNumber, const int length, const char text[] = "");

int pow2(const int degree);
