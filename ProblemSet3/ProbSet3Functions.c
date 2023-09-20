#include <stdio.h>
#include <stdlib.h>

/* compute 2*f. If f is NaN or f is Infinity, then return f */
unsigned float_twice(unsigned f) {
    //Extract sign, exponent, and fraction
    unsigned sign = f & 0x80000000; //isolates the sign bit 
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x007FFFFF;

    //If f is NaN or Infinity, return f
    if (exp == 0xFF) {
        return f;
    }

    //If f is denormalized
    if (exp == 0) {
        //Shift the fraction to the left
        frac <<= 1;
        //If the fraction overflows 
        if (frac & 0x00800000) {
            //Clear the overflow bit and increment the exponent
            frac &= 0x007FFFFF;
            exp = 1;
        }
    }
    
    //If f is normalized
    else {
        //Increment the exponent
        exp++;
        //If the exponent becomes 255 (Infinity)
        if (exp == 0xFF) {
            //Set fraction to 0 (for Infinity)
            frac = 0;
        }
    }

    //Reassemble the bits
    return sign | (exp << 23) | frac; //use or statements to combine 
}


int main() {
    unsigned f1 = 0x40C80000; // Representing 6.0 in IEEE 754
    unsigned f2 = 0x7F800000; // Representing Infinity
    unsigned f3 = 0x00000001; // Smallest denormalized number

    printf("Twice of 6.0: 0x%X\n", float_twice(f1));
    printf("Twice of Infinity: 0x%X\n", float_twice(f2));
    printf("Twice of smallest denormalized: 0x%X\n", float_twice(f3));
}