#ifndef BINARY_H
#define BINARY_H

#include <iostream>
#include <string>
#include <cmath> //for powers

//const vars
const int HIGHEST_BINARY_DIGIT = 15;// represents the amount of digits in 16 bit binary (16 - 1)
const int HIGHEST_HEX_DIGIT = 7; //represents the amount of digits in 32-bit hex (which is 8 - 1)

//functions
void outputOptions(); //output a menu for user

char intToHexLetter(int hexValue); //used to convert numbers to letter (ie. A = 10, B = 11)

int hexLetterToInt(char hexValue); //used to convert hex letters to numbers

int binaryToDecimal16(std::string userBin); //16 bit binary

int hexToDecimal32(std::string userHex); //32 bit hex to decimal

std::string decimalToHex(int inDecimal, int bitType); //arguement bitType = determines what output

std::string decimalToBinary(int inDecimal, int bitType); //uses same style of arguement as
                                                         //decimal to hex.




#endif