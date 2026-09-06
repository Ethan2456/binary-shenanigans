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
                std::cout << "Your decimal is " << decimalOut << "\n";
                std::cout << "Your hexadecimal equivalent is " << hexOut << "\n\n";
            }

        }
        if(userOption == 4){ //testing case
            int userDecimal;

            std::cin >> userDecimal;
            std::cout << "\nYour hex value is: " << decimalToHex16(userDecimal) << "\n";
        }

        
    } while(userOption != -1);




    

    return 0;
}