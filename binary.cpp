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

int hexLetterToInt(char hexValue){
    //this follows the same procedure as intToHexLetter expect it converts hex to int instead
    if(hexValue == 'A'){
        return 10;
    }
    if(hexValue == 'B'){
        return 11;
    }
    if(hexValue == 'C'){
        return 12;
    }
    if(hexValue == 'D'){
        return 13;
    }
    if(hexValue == 'E'){
        return 14;
    }
    if(hexValue == 'F'){
        return 15;
    }
    else if(hexValue > 'F'){ //error handling.
        return -1;
    }
    else{ //return the character because it's just a number.
        return hexValue - 48; //d
    }
}



int binaryToDecimal(std::string userBin){
    int sum = 0;

    //iterate starting from the right most bit
    //and then go left to right.
    for(int i = userBin.size() - 1; i >= 0; i--){ //maybe have this as a constant
        if(userBin[i] == '1'){ //power(2,(15 - i))
            //index of the right is greater, therefore, subtract by 15 or 2^15.
            sum += std::pow(2,(HIGHEST_BINARY_DIGIT - i));
        }
    } 


    return sum;
}

std::string decimalToHex16(int inDecimal){

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
    int count = 2; //change this later to hexValue.size() - 1;

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
    int sum = 0;

    //iterate backwards from the far right to left 
    for(int i = userHex.size() - 1; i >= 0; i--){
        if(userHex[i] != '0'){ //don't calculate anything that is 0
            //convert chars to numbers.
            int base = hexLetterToInt(userHex[i]);

            //the formula for calculation is usually
            // 16^(the digit you are on (0-7)) * base value (0 - F)
            sum += std::pow(16,HIGHEST_HEX_DIGIT - i) * base;
        }
    }

    return sum;
}

std::string decimalToBinary32(int inDecimal){
    //uses a similar algorithm to decimalToHex16();
    //expect for the fact that we are dividing by 2
    int quotient = 0;
    int remainder = 0;
    std::string binaryValue = "00000000000000000000000000000000"; //32 digits (because 32bits)

    //intial division
    quotient = inDecimal / 2;
    remainder = inDecimal % 2; //this should always result in 1 or 0

    //31 = last digit or the first digit needing to be replaced.
    //also +48 to convert a int to char
    binaryValue[31] = remainder + 48;

    //use a count to deincrement through the string and replace 0's with 1's when needed
    //subtract by a addtional 1 because we already indexed 31.
    int count = (binaryValue.size() - 1) - 1; //size of the string
    while(quotient != 0){

        remainder = quotient % 2;

        //int to char conversion by adding 48 since 48 = 0 in ascii. Then adding would represent
        //the char version of the int.
        binaryValue[count] = remainder + 48;

        quotient = quotient / 2;

        count -= 1;
    }

    return binaryValue;

}
