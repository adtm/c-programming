#include <stdio.h>

#define MAX_LIMIT 100
#define STEP_LIMIT 3

int main() {
    
    
    int ch;
    int step = 0;
    char line[MAX_LIMIT];
    
    int i;
    for(i = 0; i < MAX_LIMIT - 1 && ((ch = getchar()) != EOF && ch != '\n'); ++i) {
        
        if (step == STEP_LIMIT) {
            step = 0;
        } else {
            ++step;
        }
        
        if (ch == '\t') {
            for (int j = step; j < STEP_LIMIT; j++)
                line[i++] = ' ';
            --i;
        } else {
            line[i] = ch;
        }
    }
    
    ++i;
    line[i] = '\0';
    
    printf("%s \n", line);
    return 0;
}
