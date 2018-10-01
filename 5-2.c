//
// 5-2. Write getfloat, the floating-point analog of getint. What type does getfloat
// return as its function value?
//
// note: would use getch / ungetch for values, this is only a base version

#include <stdio.h>
#include <ctype.h>

#define SIZE 5

int getfloat(double *);

int main() {
    
    int n;
    double array[SIZE];
    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; ++n)
        printf("%f \n", array[n]);
    
    return 0;
}

int getfloat(double *p) {
    
    int ch;
    
    ch = getchar();
    for (*p = 0; isdigit(ch); ch = getchar()) {
        *p = *p * 10 + (ch - '0');
    }
    
    int power = 1;
    if (ch == '.') {
        ch = getchar();
        for (; isdigit(ch); ch = getchar(), power *= 10) {
            *p = *p * 10 + (ch - '0');
        }
    }
    
    *p = *p / (float) power;
    return ch;
}
