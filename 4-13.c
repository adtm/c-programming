//
//  4-13. Write a recursive version of the function reverse(s), which reverses the string s
//  in place.
//
#include <stdio.h>
#include <string.h>

#define STRING_LENGTH 10

static int idx = 0;
static void reverseString(char string[]);

int main() {
    
    char string[STRING_LENGTH] = "ABCD";
    
    printf("%s original \n", string);
    reverseString(string);
    printf("%s reversed \n", string);
    
    return 0;
}

void reverseString(char string[]) {
    if ((strlen(string) / 2) - 1 < idx) return;
    
    char temp = string[idx];
    string[idx] = string[strlen(string) - 1 - idx];
    string[strlen(string) - 1 - idx] = temp;
    
    idx++;
    reverseString(string);
}
