#include <stdio.h>


/*
* Generate mask indicating rightmost 1 in x. Assume w = 32.
* For example, 0xFF00 -> 0x0100, and 0x66C0 -> 0x0040
* If x=0, then return 0.
*/
int rightmost_one(unsigned x) {
    //Mask variable setup
    unsigned mask = 1;
    //Makes sure its not zero 
    if(x == 0) {
        return 0;
    }

    //Goes through every bit of x and checks x against the mask until the "AND" operator returns true 
    for(int i = 0; i < 32; i++) {
        if(x & mask) {
            return mask;
        }
        mask <<= 1;
    }

    return 0; 
}



int main() {
    int num = (int)2147483648U;
    int maskCheck = rightmost_one(80);
    printf("This is it: %d \n", maskCheck);
}