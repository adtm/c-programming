//
//  4.12 Adapt the ideas of printd to write a recursive version of itoa; that is, convert an
//  integer into a string by calling a recursive routine.
//
#include <stdio.h>

#define MAX_LENGTH 100

void itoa(int number);
void pushTo(int element);

char save[MAX_LENGTH];

int main() {
    
    int number = 12345;
    itoa(number);
    
    printf("%s \n", save);
}


void itoa(int number) {
    if (number < 0) {
        pushTo('-');
        number *= -1;
    }
    
    if (number / 10) {
        itoa(number / 10);
    }
    pushTo(number % 10 + '0');
}

static int freePointer = 0;
void pushTo(int element) {
    if (freePointer < MAX_LENGTH - 1) {
        save[freePointer++] = element;
    } else {
        printf("Stack Overflow!");
    }
}
