#include "binary.h"
#include <iostream>
#include <string>

int main(){

    int userOption;
    std::string userBinary;

    do {

        outputOptions();

        //input
        std::cin >> userOption;

        //output based on option picked
        //option 1: 16 bit binary        
        if(userOption == 1){
            std::cout << "Enter your 16-bit binary string: ";
            std::cin >> userBinary;

            if(userBinary.size() != 16){
                std::cout << "You did not enter a 16 bit string\n\n\n";
            }
            else{
                int decimalOut;

                decimalOut = binaryToDecimal(userBinary);

                std::cout << "The value that you entered is: " << userBinary << "\n";
                std::cout << "Your decimal is " << decimalOut << "\n\n\n";
            }

        }

        

    } while(userOption != -1);




    

    return 0;
}