#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void convert(const char* hexStr) {
    int num = 0;
    int len = strlen(hexStr);

    //Converts hex string to decimal 
    for(int i = 0; i < len; i++) {
        num *= 16;  //one hexidecimal to the left 

        if (hexStr[i] >= '0' && hexStr[i] <= '9') {
            num += hexStr[i] - '0'; 
        }
        else if (hexStr[i] >= 'A' && hexStr[i] <= 'F') {
            num += hexStr[i] - 'A' + 10; //finds the value by subtracting the ASCII val of A and then adding 10 
        }
        else if (hexStr[i] >= 'a' && hexStr[i] <= 'f') {
            num += hexStr[i] - 'a' + 10; //finds the value in the same way 
        }
    }
    printf("dec: ");
    printf("%u\n", num);

    //Converts hex string to binary 
    int extraZero = 1; //Checks to see if there are zeros in front 
    printf("bin: ");
    for(int i = 31; i >= 0; i--) { //iterates through each bit out of 32 
        if (num & (1 << i)) { //bitwise AND operation shifts one to the left 
            printf("1");
            extraZero = 0; //Because there is a one, zeros can stop being skipped 
        } else {
            if(!extraZero) {
                printf("0"); //Only prints if there is not a leading zero 
            }
        }
    }
    if(extraZero) {
        printf("0"); //print zero if there is a zero 
    }
    printf("\n");
}

int main() {
    char* symbol = "FF";
    convert(symbol);
    return 0;
}