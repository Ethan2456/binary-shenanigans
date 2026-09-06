/*
Ethan Tran
CSC2025X02
Binary and hexadecimal converter
Created on: 9/3/26

Using C++ (G++ 16.1.0 and gcc 16.1.0)
(Microsoft Visual C++ v14)

Description:
The program provides the user with 3 options in the terminal. The three options being
1. Convert a 16-bit binary value to decimal and hexadecimal(16-bit)
2. Convert a 32-bit hexadecimal value to decimal and binary(32-bit)
3. And convert an integer to a 32-bit hexadecimal and a 32-bit binary. 
There is also an option to exit out the program by typing -1 instead.
(Note: the program will keep asking for input until you type -1)

The program for binary and hexadecimal conversion to decimal uses a formula where
you go through an entire string of binary and add the sum ((1 or 0) * 2^(spot in the binary))
when the value of the index is 1. For hexadecimal it's the same thing expect it uses the 
formula ((value of the digit) * 16^(spot/index in the hexadecimal)) The reason why is because
each spot represents a power. For example, 0100 in binary the 1 represents 2^2 which is 4.

For the integer to binary/hex conversion I used a dividing algorithm where you divide the quotient
until it reaches 0. And the remainder of each quotient represents the value of the hex or binary.
*/
#include "binary.h" //where function prototypes are stored
#include <iostream> //input output
#include <string>

int main(){

    //store the option of the user
    int userOption;

    do {
        outputOptions(); //output menu of options

        std::cin >> userOption; //handle input and output based on option picked

        //option 1: 16 bit binary        
        if(userOption == 1){
            std::string userBinary; //to store user input

            std::cout << "\nEnter your 16-bit binary string: ";
            std::cin >> userBinary;

            if(userBinary.size() != 16){ //handle if they enter something that is 17 bits
                std::cout << "You did not enter a 16 bit string\n\n\n";
            }
            else{
                int decimalOut; //place to store a decimal to be outputted
                std::string hexOut; //store a hex to be outputted

                decimalOut = binaryToDecimal16(userBinary);
                //use the decimalOut arguement to find the hexadecimal equivalent
                hexOut = decimalToHex(decimalOut,16); //arguement 16bits

                std::cout << "The value that you entered is: " << userBinary << "\n";
                std::cout << "Your decimal is: " << decimalOut << "\n";
                std::cout << "Your hexadecimal equivalent is: " << hexOut << "\n\n";
            }

        }
        //option 2: 32-bit hex to decimal
        if(userOption == 2){
            std::string userHex; //store user hexdecimal

            std::cout << "\nNOTE: DO NOT INCLUDE 0x (Ex. 0012A231)\n";
            std::cout << "Enter your 32-bit hexadecimal value: ";
            std::cin >> userHex;

            if(userHex.size() != 8){ //handle if they input something more/greater
                std::cout << "You did not enter a 32-bit hexadecimal value. \n\n";
            }
            else{
                int decimalOut;
                std::string binaryOut; //a place to store binary

                decimalOut = hexToDecimal32(userHex);
                //use the decimalOut arguement to find the hexadecimal equivalent
                binaryOut = decimalToBinary(decimalOut,32); //arguement 32 = 32bits
                
                std::cout << "Your value that you entered is: " << userHex << "\n";
                std::cout << "Your decimal is: " << decimalOut << "\n";
                std::cout << "The binary equivalent is: " << binaryOut << "\n\n";

            }
        }
        //option 3 convert a decimal to binary or hex. (conversion will be 32 bits)
        if(userOption == 3){
            int userInt;
            std::string binaryOut;
            std::string hexOut;

            std::cout << "\nEnter an integer: ";
            std::cin >> userInt;

            binaryOut = decimalToBinary(userInt,32); //arguement (32) = convert to 32-bit binary
            hexOut = decimalToHex(userInt,32); //arguement (32) = convert to 32-bit hex

            std::cout << "The value that you entered is: " << userInt << "\n";
            std::cout << "The binary equivalent(32-bits) is: " << binaryOut << "\n";
            std::cout << "The hex equivalent(32-bits) is: " << hexOut << "\n\n";

        }

        
    } while(userOption != -1); //repeat until the user enters -1 or the number to exit.

    return 0;
}