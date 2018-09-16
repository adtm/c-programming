#include <stdio.h>

#define MAX_LENGTH 1000
#define LIMIT 80

int readline(char to[]);

int main() {
    
    char line[MAX_LENGTH];
    int length;
    
    while((length = readline(line)) && length > 0) {
        if (length >= LIMIT)
            printf("%s \n", line);
    }
    
}

int readline(char save[]) {
    
    int i;
    int ch;
    
    for (i = 0; i < MAX_LENGTH - 1 && (ch = getchar()) != EOF && ch != '\n'; ++i) {
        save[i] = ch;
    }
    save[++i] = '\0';
    
    return i;
}
