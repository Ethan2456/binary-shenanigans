#ifndef BINARY_H
#define BINARY_H

#include <iostream>
#include <string>
#include <cmath> //for powers
#include <algorithm> //for std::reverse

//const vars
const int HIGHEST_BINARY_BIT = 15;

//functions
void outputOptions(); 

char intToHexLetter(int hexValue); //used to convert numbers to letter (ie. A = 10, B = 11)

int binaryToDecimal(std::string userBin); //16 bit binary

std::string decimalToHex16(int inDecimal); //outputs a hex in 16 bit for the 1st option
//as you need to display the binary, decimal representation, and hex representation in 16.

int hexToDecimal32(std::string userHex); //32 bit hex

std::string decimalToBinary32(int inDecimal); // outputs binary in 32 bit for the 2nd option


int power(int base, int amount);



#endif