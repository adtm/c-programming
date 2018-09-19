//
// 2.4 Write an alternative version of squeeze(s1,s2) that deletes each character in s1
// that matches any character in the string s2.
//

#include <stdio.h>

#define ASCII_TABLE 127

void squeeze(char s1[], char s2[]);

int main() {
    char original[] = {'d', 'b', 'o','g', 'a', 'a', 'c', '\0'};
    char alphabet[] = {'a', 'b', 'd', '\0'};
    
    printf("%s before \n", original);
    squeeze(original, alphabet);
    printf("%s after \n", original);
    
    return 1;
}

void squeeze(char org[], char alph[]) {
    // store all alphabet letters to an array of ASCII symbols
    // loop the original array
    // if the element doesn't exist, don't add it to j++
    // if the element does exist, add it to j++
    
    int ascii_table[ASCII_TABLE];
    for (int i = 0; i < ASCII_TABLE; ++i)
        ascii_table[i] = 0;
    
    int i = 0;
    while(alph[i] != '\0') {
        int ch = alph[i];
        ascii_table[ch] = 1;
        i++;
    }
    
    int j, z;
    for (j = z = 0; org[j] != '\0'; ++j) {
        int ch = org[j];
        if (ascii_table[ch] != 1)
            org[z++] = ch;
    }
    org[z] = '\0';
}
