//
// 2.5 Write the function any(s1,s2), which returns the first location in a string s1 where
// any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
//
// (The standard library function strpbrk does the same job but returns a pointer to the location.)
//
#include <stdio.h>

#define ASCII_TABLE 127

enum boolean {
    FALSE,
    TRUE
};

int any(char s1[], char s2[]);

int main() {
    
    char original[] = {'d','o','g','\0'};
    char alphabet[] = {'a','b','\0'};
    
    int first_occurance = any(original, alphabet);
    printf("%d \n", first_occurance);
    
    return 0;
}

int any(char org[], char alph[]) {
    
    int ascii_table[ASCII_TABLE];
    
    int i;
    for (i = 0; i < ASCII_TABLE; ++i)
        ascii_table[i] = '\0';
    
    i = 0;
    while(alph[i] != '\0') {
        int ch = alph[i];
        ascii_table[ch] = TRUE;
        i++;
    }
    
    i = 0;
    while(org[i] != '\0') {
        int ch = org[i];
        if (ascii_table[ch]) {
            return i;
        }
        i++;
    }
    
    return -1;
}

