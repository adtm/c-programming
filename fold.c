//
// 1.22. Write a program to ``fold'' long input lines into two or more shorter lines after the
// last non-blank character that occurs before the n-th column of input. Make sure your program does
// something intelligent with very long lines, and if there are no blanks or tabs before the specified
// column.
//
#include <stdio.h>

#define MAX_LIMIT 100
#define MAX_LENGTH 4

void simpleTruncation(void);
void cleanArray(char what[]);
int readline(char to[]);

int main() {
    
    int length;
    char line[MAX_LIMIT];
    
    while((length = readline(line)) && length > 0)
        printf("%s \n", line);
    
}

void cleanArray(char to[]) {
    int i = 0;
    while(to[i] != '\0') {
        to[i] = '\0';
        ++i;
    }
}

int readline(char save[]) {
    
    cleanArray(save);
    
    int i;
    int ch;
    
    for(i = 0; i < MAX_LIMIT && (ch = getchar()) != EOF && ch != '\n'; ++i)
        save[i] = ch;
    
    int c;
    for (c = 1; c <= i; ++c) {
        putchar(save[c - 1]);
        
        if (c % MAX_LENGTH == 0 && c >= MAX_LENGTH) {
            if (save[c] != ' ' && save[c - 1] != ' ') {
                putchar('-');
                putchar('\n');
                putchar('-');
            } else {
                putchar('\n');
            }
        }
    }
    
    putchar('\n');
    return i;
}

void simpleTruncation() {
    int i;
    int ch;
    
    for (i = 0; i < MAX_LIMIT && ((ch = getchar()) != EOF) && ch != '\n'; ++i) {
        if (ch != ' ' && (i % MAX_LENGTH == 0 || i > MAX_LENGTH)) {
            putchar('\n');
            i = 0;
        }
        putchar(ch);
    }
    putchar('\n');
}
