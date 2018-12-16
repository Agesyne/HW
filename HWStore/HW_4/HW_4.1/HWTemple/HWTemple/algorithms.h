#pragma once

void decToTwosComplement(const int number, int *bitNumber[]);

void addBitNumbers(const int bitNumber1[], const int bitNumber2[], int *addResult[]);

int twosComplementToDec(int addResult[]);

void printBitNumber(int bitNumber[], const char text[] = "");
