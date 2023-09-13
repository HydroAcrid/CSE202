#include <stdio.h>


/*
* Generate mask indicating rightmost 1 in x. Assume w = 32.
* For example, 0xFF00 -> 0x0100, and 0x66C0 -> 0x0040
* If x=0, then return 0.
*/
int rightmost_one(unsigned x);



int main() {
    int num = (int)2147483648U;
    printf("This is it: %d \n", num);
}