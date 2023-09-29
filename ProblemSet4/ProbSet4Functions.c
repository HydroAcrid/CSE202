#include <stdio.h>

long loop(long x, int n) { 
    // Variable setup 
	long result = 0;              
	long mask;

    // Set mask to 1 and left shift it by n positions in each loop
	for(mask = 1; mask != 0; mask = mask << n)  {  
        // Update result with  OR between result and (x & mask)
        result |= (x & mask);     	
    }
	return result;
}

long switchFunc(long x, long n) {
    long result = x;
    switch(n - 60) {
        case 0:
        case 2:
            result = x * 8;
            break;
        case 3:
            result = x >> 3;
            break;
        case 4:
            result = (x << 4) - x;
            break;
        case 5:
            result = x * x;
            break;
        default:
            result = x + 75;
            break;
    }
    return result;
}

 long switch_fn(long x, long n) {
    long result = x;
    switch(n) {
        case 60:
        case 62:
            result = x * 8;
            break;
        case 63:
            result = x >> 3;
            break;
        case 64:
            result = (x * 16) - x;
            break;
        case 65:
            result = x * x;
            break;
        default:
            result = x + 75;
            break;
    }
    return result;
}



int main() {
    long answer = switchFunc(3004567, 8003938);
    printf("This is the output: %ld\n", answer);
    answer = switch_fn(3004567,8003938);
    printf("This is the output: %ld", answer);

}





