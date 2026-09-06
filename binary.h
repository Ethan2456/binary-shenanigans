#ifndef BINARY_H
#define BINARY_H

#include <iostream>
#include <string>
#include <cmath> //for powers

//const vars
const int HIGHEST_BINARY_DIGIT = 15;// represents the amount of digits in 16 bit binary (16 - 1)
const int HIGHEST_HEX_DIGIT = 7; //represents the amount of digits in 32-bit hex (which is 8 - 1)

//functions
void outputOptions(); 

char intToHexLetter(int hexValue); //used to convert numbers to letter (ie. A = 10, B = 11)

int hexLetterToInt(char hexValue); //used to convert hex letters to numbers

int binaryToDecimal(std::string userBin); //16 bit binary

std::string decimalToHex16(int inDecimal); //outputs a hex in 16 bit for the 1st option
//as you need to display the binary, decimal representation, and hex representation in 16.

int hexToDecimal32(std::string userHex); //32 bit hex

std::string decimalToBinary32(int inDecimal); // outputs binary in 32 bit for the 2nd option


int power(int base, int amount);



#endif