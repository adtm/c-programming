#include <stdio.h>

#define MAX_LENGTH 1000

int main() {
    
    int ch;
    char line[MAX_LENGTH];
    char reverse[MAX_LENGTH];
    
    int i;
    for(i = 0; i < MAX_LENGTH - 1 && ((ch = getchar()) != EOF && ch != '\n'); ++i)
        line[i] = ch;
    --i; // remove because of termination clause
    
    int j;
    for (j = i; j >= 0; j--)
        reverse[i - j] = line[j];
    
    reverse[++i] = '\0';
    
    printf("%s, original \n", line);
    printf("%s, reverse \n", reverse);
    
    return 0;
}
