//
// 1.23. Write a program to remove all comments from a C program. Don't forget to handle
// quoted strings and character constants properly. C comments don't nest.
//

#include <stdio.h>

#define LIMIT 1000

int doubleArguments = 0;

int readline(char save[]);
void cleanArrayFrom(char clean[], int from, int to);
void cleanArray(char line[]);

int main() {
    
    int length;
    char line[LIMIT];
    
    while ((length = readline(line)) && length > 0)
        printf("%s \n", line);
    
    return 0;
}

void cleanArrayFrom(char line[], int from, int to) {
    for (; from < to; from++) {
        line[from] = ' ';
    }
}

void cleanArray(char line[]) {
    int i = 0;
    while(line[i] != '\0') {
        line[i] = '\0';
        ++i;
    }
}

int readline(char save[]) {
    
    cleanArray(save);
    
    int ch;
    int i;
    
    for (i = 0; i < LIMIT - 1 && ((ch = getchar()) != EOF && ch != '\n'); ++i)
        save[i] = ch;
    
    ++i;
    save[i] = '\0';
    
    extern int doubleArguments;
    
    int j;
    for (j = 0; j < i; ++j) {
        
        // 1. When it's //
        if (save[j] == '/' && save[j + 1] == '/') {
            cleanArrayFrom(save, j, i);
            break;
        }
        
        // 2. When it's /* */
        
        if (save[j] == '/' && save[j + 1] == '*') doubleArguments = 1;
        if (save[j] == '*' && save[j + 1] == '/' && doubleArguments) {
            save[j] = ' ';
            save[j + 1] = ' ';
            doubleArguments = 0;
        }
        if (doubleArguments) save[j] = ' ';
        
        // 3. When it's /*
        //               *
        //              /*
        if (doubleArguments && save[j] == '*') {
            cleanArrayFrom(save, j, i);
            break;
        }
    }
    
    return i;
}
