#ifndef BINARY_H
#define BINARY_H

#include <iostream> //input output
#include <string> 
#include <cmath> //for powers (pow function)

//const vars
const int HIGHEST_BINARY_DIGIT = 15;// represents the amount of digits in 16 bit binary (16 - 1)
const int HIGHEST_HEX_DIGIT = 7; //represents the amount of digits in 32-bit hex (which is 8 - 1)

//functions
void outputOptions(); //output a menu for user

//used to convert/check an integer or hex value to a letter (ie. A = 10, B = 11)
char intToHexLetter(int hexValue); 

//used in the hex conversion functions, takes a hexValue (A,B,C) and converts/checks the numbers (10,11,12)
int hexLetterToInt(char hexLetter); 

//takes a 16-bit binary as a string and converts to a decimal
int binaryToDecimal16(std::string userBin);

//takes a 32-bit hexadecimal as a string and converts to a decimal
int hexToDecimal32(std::string userHex);

//takes a decimal and converts to hex and takes an arguement for the bit type 
//(can handle only 16 or 32 bits)
std::string decimalToHex(int inDecimal, int bitType); 

//takes a decimal and converts to binary. also takes an arguement for the bit type (16 or 32 bits)
std::string decimalToBinary(int inDecimal, int bitType);




#endif