//
//  5-5. Write versions of the library functions strncpy, strncat, and strncmp, which
//  operate on at most the first n characters of their argument strings. For example, strncpy(s,t,n)
//  copies at most n characters of t to s
//
#include <stdio.h>

#define LENGTH 100
enum boolean {
    FALSE,
    TRUE
};

int strCmp(char *first, char *second, int count);
void strnCat(char *first, char *second, int count);

int main() {
    
    char first[LENGTH] = "the_weather_is_";
    char second[LENGTH] = "the_super_nice";
    
    strnCat(first, second, 9);
    printf("%s, \n", first);
    
    int result = strCmp(first, second, 3);
    printf("%s \n", result == TRUE ? "equals" : "not-equal");
    
    return 0;
}

void strnCat(char *f, char *s, int n) {
    
    while(*f != '\0')
        f++;
    
    int i;
    for (i = 0; i < n; ++i) {
        *f++ = *s++;
    }
}

int strCmp(char *f, char *s, int n) {
    
    int i;
    for (i = 0; i < n; ++i, f++, s++)
        if (*f != *s)
            return FALSE;
    
    return TRUE;
}
