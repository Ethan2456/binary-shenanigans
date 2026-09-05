#include "binary.h"

void outputOptions(){
    std::cout << "Welcome to the binary converter.\n";
    std::cout << "What is your choice of input\n\n";
    std::cout << "1) 16-bit Binary\n";
    std::cout << "2) 32-bit Hexadecimal\n";
    std::cout << "3) interger or decimal\n";
    std::cout << "-1) to exit out the program\n";
    std::cout << "Press the associated number to select the option\n\n";
}

//ignore this im using cmath instead
int power(int base, int amount){
    int sum = base;

    if(amount == 0){
        return 1;
    }

    for(int i = 0; i < amount - 1; i++){
        sum *= base;
    }
    return sum;
}


int binaryToDecimal(std::string userBin){
    int sum = 0;

    //iterate starting from the right most bit
    //and then go left to right.
    for(int i = userBin.size() - 1; i >= 0; i--){ //maybe have this as a constant
        if(userBin[i] == '1'){ //power(2,(15 - i))
            //index of the right is greater, therefore, subtract by 15 or 2^15.
            sum += std::pow(2,(HIGHEST_BINARY_BIT - i));
        }
    } 


    return sum;
}