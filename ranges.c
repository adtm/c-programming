//
// 2.1 Write a program to determine the ranges of char, short, int, and long variables,
// both signed and unsigned, by printing appropriate values from standard headers and by direct
// computation. Harder if you compute them: determine the ranges of the various floating-point
//types

// same logic to char, short, int, long

#include <stdio.h>

int power(int what, int how);
void signed_range(signed short int_rang);
void unsigned_range(unsigned short int_rang);

int main() {
    
    // short signed int -> (min / max)
    printf("short signed int \n");
    signed short sign_range = 0;
    signed_range(sign_range);
    
    printf("\n");
    
    // short unsigned int -> (min / max)
    printf("long unsigned int \n");
    unsigned short unsign_range = 0;
    unsigned_range(unsign_range);
    
    return 0;
}

int power(int what, int how) {
    
    int number = 1;
    for (int i = 0; i < how; ++i)
        number *= what;
    
    return number;
}

void signed_range(signed short short_rang) {
    int i = 0;
    while (short_rang >= 0) {
        short_rang = power(2, i);
        if (short_rang < 0) {
            printf("min: %d \n", short_rang);
            printf("max: %d \n", (short_rang + 1) * -1);
            break;
        }
        ++i;
    }
}

void unsigned_range(unsigned short int_range) {
    
    int i = 1;
    while (int_range >= 0) {
        int_range = power(2, i);
        if (int_range == 0) {
            int max = power(2, i) - 1;
            
            printf("min: %d \n", 0);
            printf("max: %d \n", max);
            break;
        }
        ++i;
    }
}
