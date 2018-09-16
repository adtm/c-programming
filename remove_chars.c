//
// 1.18. Write a program to remove trailing blanks and tabs from each line of input, and to
// delete entirely blank lines.
//

#include <stdio.h>

#define MAX_LENGTH 1000

void readline(char to[]);
void cleanArray(char to[]);

int main() {
    
    char line[MAX_LENGTH];
    while(1) {
        readline(line);
        printf("%s-\n", line);
    }
    
}

void cleanArray(char toClean[]) {
    int i = 0;
    while(toClean[i] != '\0') {
        toClean[i] = '\0';
        ++i;
    }
}

void readline(char save[]) {
    
    int ch;
    int c = 0;
    int hasChar = 0;
    
    cleanArray(save);
    for (int i = 0; i < MAX_LENGTH - 1 && ((ch = getchar()) != EOF && ch != '\n'); ++i) {
        if (ch == ' ' || ch == '\t') continue;
        else hasChar = 1;
        
        if (hasChar) {
            save[c] = ch;
            ++c;
        }
    }
    
    for (int z = c; z >= 0 && (save[z] == '\t' || save[z] == ' '); --z)
        save[z] = '\0';
}
