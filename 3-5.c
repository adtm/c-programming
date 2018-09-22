//
// 3-5. Write the function itob(n,s,b) that converts the integer n into a base b character
// representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in
// s.
//

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void itob(int n, char s[], int b);
void reverse(char input[]);

int main() {
    
    int number = -12345;
    int base = 5;
    
    char representation[MAX_LENGTH];
    
    itob(number, representation, base);
    printf("%s af \n", representation);
    
    return 0;
}

void itob(int number, char store[], int base) {
    
    int positive = number <= 0 ? -1 : 1;
    number = number >= 0 ? number : -1 * number;
    
    int x = 0;
    do {
        int num = number % base;
        store[x++] = num <= 9 ? num + '0' : num - 'a' + '0';
    } while ((number = number / base) > 0);
    
    if (positive == -1)
        store[x++] = '-';
    
    store[x++] = '\0';
    reverse(store);
}

void reverse(char input[]) {
    int i, j, temp;
    for(i = 0, j = strlen(input) - 1; i < j; ++i, --j) {
        temp = input[j];
        input[j] = input[i];
        input[i] = temp;
    }
}
