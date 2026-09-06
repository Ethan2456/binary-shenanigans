#include "binary.h"
#include <iostream>
#include <string>

int main(){

    int userOption;

    do {

        outputOptions();

        //input
        std::cin >> userOption;

        //output based on option picked
        //option 1: 16 bit binary        
        if(userOption == 1){
            std::string userBinary;

            std::cout << "Enter your 16-bit binary string: ";
            std::cin >> userBinary;

            if(userBinary.size() != 16){
                std::cout << "You did not enter a 16 bit string\n\n\n";
            }
            else{
                int decimalOut;
                std::string hexOut;

                decimalOut = binaryToDecimal(userBinary);
                hexOut = decimalToHex16(decimalOut);

                std::cout << "The value that you entered is: " << userBinary << "\n";
                std::cout << "Your decimal is: " << decimalOut << "\n";
                std::cout << "Your hexadecimal equivalent is: " << hexOut << "\n\n";
            }

        }
        //option 2: 32-bit hex to decimal
        if(userOption == 2){
            std::string userHex;

            std::cout << "NOTE: DO NOT INCLUDE 0x\n";
            std::cout << "Enter your 32-bit hexadecimal value: ";
            std::cin >> userHex;

            if(userHex.size() != 8){
                std::cout << "You did not enter a 32-bit hexadecimal value. \n\n";
            }
            else{
                int decimalOut;
                std::string binaryOut;

                decimalOut = hexToDecimal32(userHex);
                binaryOut = decimalToBinary32(decimalOut);
                
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

            std::cout << "Enter an integer: ";
            std::cin >> userInt;

            binaryOut = decimalToBinary32(userInt);
            hexOut = decimalToHex32(userInt);

            std::cout << "The value that you entered is: " << userInt << "\n";
            std::cout << "The binary equivalent(32-bits) is: " << binaryOut << "\n";
            std::cout << "The hex equivalent(32-bits) is: " << hexOut << "\n";


        }
        if(userOption == 4){ //testing case
            int userDecimal;

            std::cin >> userDecimal;
            std::cout << "\nYour binary value is: " << decimalToBinary32(userDecimal)<< "\n";
        }

        
    } while(userOption != -1);




    

    return 0;
}