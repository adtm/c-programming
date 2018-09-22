//
// 4-1. Write the function strindex(s,t) which returns the position of the rightmost
// occurrence of t in s, or -1 if there is none.
//
#include <stdio.h>
#include <string.h>

#define MAX_LIMIT 1000

int getLine(char to[], int limit);
int strIndex(char input[], char term[]);

int main() {
    
    int length;
    char line[MAX_LIMIT];
    
    while ((length = getLine(line, MAX_LIMIT)) && length > 0)
        printf("%d index, \n", strIndex(line, "ould"));
    
    return 0;
}

int getLine(char to[], int limit) {
    
    int ch, i;
    i = 0;
    
    while (limit - 1 > i && (ch = getchar()) != EOF && ch != '\n')
        to[i++] = ch;
    
    if (ch == '\n')
        to[i++] = ch;
    to[i] = '\0';
    
    return i;
}

int strIndex(char input[], char term[]) {
    
    int i, j, z;
    int right_most = -1;
    for(i = 0; i < strlen(input); ++i) {
        
        for (j = i, z = 0; term[z] != '\0' && input[j] == term[z]; ++j, ++z)
            ;
        
        if (z > 0 && term[z] == '\0')
            right_most = right_most > i ? right_most : i;
    }
    
    return right_most;
}
