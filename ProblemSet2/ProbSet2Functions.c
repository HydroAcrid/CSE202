#include <stdio.h>
#include <limits.h>

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


int numbah6(int x) {
     // Multiply by 5
    int output = (x << 2) + x;  // 4*x + x -> shifts to the left twice than adds x. 2^2 = 4 

    // Divide by 8
    return output >> 3; //Would use / 8 but it said to follow bit-level integer coding rules. 2^3 = 8
}

/* Determine whether arguments can be subtracted without overflow */
int tsub_ok(int x, int y) {
    // Check for overflow conditions
    if ((x > 0 && y < INT_MIN + x) || (x < 0 && y > INT_MAX + x)) { //This shows what happens when subtracting a negative number from a positive number or vice verse 
        return 0;  // Overflow
    }
    return 1;  // No overflow
}



int main() {
    int num = (int)2147483648U;
    int maskCheck = rightmost_one(80);
    printf("This is it: %d \n", maskCheck);
    printf("mul5div8(10) = %d\n", mul5div8(10));  // Should print 6
    printf("mul5div8(-10) = %d\n", mul5div8(-10));  // Should print -6
}