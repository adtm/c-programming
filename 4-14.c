//
//  4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t.
//  (Block structure will help.)
//
#include <stdio.h>

#undef swap
#define swap(t, x, y) { t temp = x; x = y; y = temp; }

int main() {
    int x = 10;
    int y = 99;
    
    printf("x: %d, y: %d \n", x, y);
    swap(int, x, y);
    printf("x: %d, y: %d \n", x, y);
}
