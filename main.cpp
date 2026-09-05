#include "binary.h"
#include <iostream>
#include <string>

int main(){

    int userOption;
    std::string userBinary;

    outputOptions();

    //input
    std::cin >> userOption;

    //output based on option picked
    if(userOption == 1){
        std::cout << "Enter your 16-bit binary string: ";
        std::cin >> userBinary;

        if(userBinary.size() != 16){
            std::cout << "You did not enter a 16 bit string\n";
            std::cout << "Terminating program.\n";
        }
        else{
            int decimalOut;

            decimalOut = binaryToDecimal(userBinary);

            std::cout << "Your decimal is " << decimalOut << "\n";
        }

    }
    if(userOption == 0){ //testing for the power functino
        int userBaseNum;
        int userAmountNum;

        std::cin >> userBaseNum;
        std::cin >> userAmountNum;

        std::cout << power(userBaseNum, userAmountNum) << "\n";
    }
    

    return 0;
}