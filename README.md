# binary shenanigans

Assignment for CSC2025X02. A binary/hexadecimal converter in C++.

## Algorithm explaination

For the Algorithms I chose 2. 1 for converting hexadecimal and binary to decimals and 1 for converting decimal to either hexadecimal or binary.

For the conversion of hexadecimal and binary to decimal. I used a method where you continually divide the number and its quotient over and over again until the value is equal to 0. For each division of the quotient, I would take the remainder and use that as the value of the hexadecimal or binary. 

A source I used for this method was [GeeksforGeeks](https://www.geeksforgeeks.org/utilities/decimal-to-hex-converter/)

For the conversion of binary or hexadecimal to decimal. I just iterated through the entire string (starting from the right) and then iterating left. And then multiplying the value of the index with either (2^n) for binary and (16^n) for hexadecimal. 

n would be the size of the string (which was either 15 or 7 because the binary that needed to be outputted was 16 bits and the hex that needed to be outputted was 32 bits or 8 values) - the current index that we were on. It looked something like this.

```
(2 or 16)^((15 or 7) - i)
```
