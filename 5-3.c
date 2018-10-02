//
//  5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
//  strcat(s,t) copies the string t to the end of s
//

#include <stdio.h>

#define LENGTH 100

void strextend(char *f, char *s);

int main() {
    char first[LENGTH] = "first";
    char second[LENGTH] = "_second";
    
    strextend(first, second);
    
    printf("%s, \n", first);
    printf("%s, \n", second);
}

void strextend(char *f, char *s) {
    
    while (*f != '\0')
        f++;
    
    while(*s != '\0') {
        *f = *s;
        f++;
        s++;
    }
}
