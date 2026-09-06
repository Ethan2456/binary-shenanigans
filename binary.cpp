#include "binary.h"

void outputOptions(){
    std::cout << "Welcome to the binary converter.\n";
    std::cout << "What is your choice of input\n";
    std::cout << "1) 16-bit Binary\n";
    std::cout << "2) 32-bit Hexadecimal\n";
    std::cout << "3) integer or decimal\n";
    std::cout << "or enter -1 to exit out the program\n";
    std::cout << "Enter the associated number to select the option: ";
}

//handle converting integers to hexletters
char intToHexLetter(int hexValue){
    //checks for the 5 different letters
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
    else if(hexValue > 15){ //error handling. (outputs ? if bad)
        return '?';
    }
    else{ //return the number because its not a letter
        //+48 because 48 in ascii starts at 0. And adding the hexValue + 0 would give you
        //the number in character form (just the way I had to convert int->char)
        return hexValue + 48; 
    }
}

//convert hexValues to integers
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
        //subtracting by 48 gives the true integer value as ex. 2 = 50 in ascii, 0 = 48 in ascii
        //therefore, subtracting by 48 gives you the true value for integers 0-9.
        return hexValue - 48; 
    }
}


//convert a 16bit binary value to a decimal 
int binaryToDecimal16(std::string userBin){
    int sum = 0;

    //iterate backwards starting from the right most bit
    //and then go right to left.
    for(int i = userBin.size() - 1; i >= 0; i--){
        if(userBin[i] == '1'){
            //index of the right is greater, therefore, subtract by 15 or 2^15.
            //which is the highest binary digit you can have.
            sum += std::pow(2,(HIGHEST_BINARY_DIGIT - i));
        }
    } 

    return sum;
}

//convert a 32 bit hex value to a decimal
int hexToDecimal32(std::string userHex){
    int sum = 0;

    //iterate backwards from the far right, then going right to left 
    for(int i = userHex.size() - 1; i >= 0; i--){
        if(userHex[i] != '0'){ //don't calculate anything that is 0 (because its just 0)
            //convert chars to numbers and handles letters like A-F.
            int base = hexLetterToInt(userHex[i]);

            //the formula for calculation is usually
            // 16^(the digit you are on (0-7)) * base value (0 - F)
            sum += std::pow(16,HIGHEST_HEX_DIGIT - i) * base;
        }
    }

    return sum;
}

//convert decimal to a hexadecimal and can choose 16 or 32 bits as the result.
std::string decimalToHex(int inDecimal, int bitType){
    int quotient = 0; //quotient and remainder for the algorithm
    int remainder = 0;
    int maxDigits = 0; //used to represent the size of the indexes for 32 and 16 bits
    std::string hexValue; //string to store empty hex values

    //handle what needs to be outputted (whether that be 32 or 16)
    if(bitType == 32){
        hexValue = "00000000"; //size for 32 bits
        maxDigits = hexValue.size() - 1; //max index of hexvalue of 32 bits

        //intial divison
        quotient = inDecimal / 16;
        remainder = inDecimal % 16;
        remainder = intToHexLetter(remainder);
        hexValue[maxDigits] = remainder; //add this to the first value of the Hex (16^0)

        //count to iterate through the hex (start at 2 since we already did 3)
        int count = (maxDigits) - 1;

        //keep dividing the quotient intill it reaches 0
        //if the quotient (from the intial divide) is already 0 then just return the hex.
        while(quotient != 0){
     
            //remainder = what value it needs to represent
            remainder = quotient % 16;

            //add value to the hexValue string
            hexValue[count] = intToHexLetter(remainder);
            quotient = quotient / 16;

            //go left of the hex value
            count -= 1;
        }

        return hexValue;
    }
    if(bitType == 16){
        hexValue = "0000"; //this is the size for 16 bits
        maxDigits = hexValue.size() - 1; //max index of hexvalue for 16 bits

        //use the same formula as above expect handle 16 bits instead of 32
        //intial divison
        quotient = inDecimal / 16;
        remainder = inDecimal % 16; 
        remainder = intToHexLetter(remainder);
        hexValue[maxDigits] = remainder; //add this to the first value of the Hex (16^0)

        //count to iterate through the hex (start at 2 since we already did 3)
        int count = (maxDigits) - 1;

        //keep dividing the quotient intill it reaches 0
        //same as before...
        while(quotient != 0){       
            remainder = quotient % 16; //remainder = what value it needs to represent
            hexValue[count] = intToHexLetter(remainder); //add value to complete string
            quotient = quotient / 16;
            count -= 1;
        }

        return hexValue;
    }
    else{ //error handling
        return "Invalid bit Type detected (Can only be 16 or 32)\n";
    }

}

std::string decimalToBinary(int inDecimal, int bitType){
    //uses a similar algorithm to decimalToHex();
    //expect for the fact that we are dividing by 2
    int quotient = 0;
    int remainder = 0;
    int maxDigits;
    std::string binaryValue;

    //handles whether the output needs to be in 32 bits or 16 bits
    if(bitType == 32){
        binaryValue = "00000000000000000000000000000000"; //32 digits (because 32bits)
        maxDigits = binaryValue.size() - 1; // size of the index binaryValue - 1

        //intial division
        quotient = inDecimal / 2;
        remainder = inDecimal % 2; //this should always result in 1 or 0

        //maxdigit = last digit or the first digit needing to be replaced.
        //also +48 to convert a int to char
        binaryValue[maxDigits] = remainder + 48;

        //use a count to deincrement through the string and replace 0's with 1's when needed
        //subtract by a addtional 1 because we already indexed maxDigit.
        int count = (maxDigits) - 1; //size of the string
        while(quotient != 0){

            remainder = quotient % 2;

            //int to char conversion by adding 48 since 48 = 0 in ascii. Then adding would
            //represent the char version of the int.
            binaryValue[count] = remainder + 48;

            quotient = quotient / 2;

            count -= 1;
        }

        return binaryValue;
    }
    //if the arguement was 16-bit
    if(bitType == 16){
        binaryValue = "0000000000000000";
        maxDigits = binaryValue.size() - 1; //size of the index

        //same algorithm as first conditional
        //intial division
        quotient = inDecimal / 2;
        remainder = inDecimal % 2;
        binaryValue[maxDigits] = remainder + 48; //+48 to convert a int to char

        //use a count to deincrement through the string
        int count = (maxDigits) - 1; //size of the string (after handling first digit)
        while(quotient != 0){

            remainder = quotient % 2;

            //int to char conversion
            binaryValue[count] = remainder + 48;

            quotient = quotient / 2;

            count -= 1;
        }

        return binaryValue;
    }
    else{ //error handling 
        return "Invalid bit Type detected (Can only be 16 or 32)\n";
    }

}