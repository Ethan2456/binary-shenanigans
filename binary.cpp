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

//handle converting integers to hexletters
char intToHexLetter(int hexValue){
    if(hexValue == 10){
        return 'A';
    }
    if(hexValue == 11){
        return 'B';
    }
    if(hexValue == 12){
        return 'C';
    }
    if(hexValue == 13){
        return 'D';
    }
    if(hexValue == 14){
        return 'E';
    }
    if(hexValue == 15){
        return 'F';
    }
    else if(hexValue > 15){ //error handling.
        return '?';
    }
    else{ //return the number because its not a letter
        //+48 because 48 in ascii starts at 0. And adding the hexValue + 0 would give you
        //the number in character form (just the way I had to convert int->char)
        return hexValue + 48; 
    }
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

std::string decimalToHex16(int inDecimal){
    //hexLetters[6] = {'A','B','C','D','E','F'};

    //divide by 16 keep quoitent and find remainder. then the remainder is the hex value
    int quotient = 0;
    int remainder = 0;
    //declare a hexValue string to store hex values in
    std::string hexValue = "0000";

    //intial divison
    quotient = inDecimal / 16;
    remainder = inDecimal % 16;
    remainder = intToHexLetter(remainder);
    hexValue[3] = remainder; //add this to the first value of the Hex (16^0)

    //count to iterate through the hex (start at 2(the third element of the hexvalue))
    int count = 2;

    //keep dividing the quotient intill it reaches 0
    while(quotient != 0){
     
        //remainder = what value it needs to represent
        remainder = quotient % 16;

        //add value to a string
        hexValue[count] = intToHexLetter(remainder);

        quotient = quotient / 16;

        //go left of the hex value
        count -= 1;

    }

    return hexValue;

}

//convert a 32 bit hex value to a decimal
int hexToDecimal32(std::string userHex){

}



//ignore this im using cmath instead
/*
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
*/