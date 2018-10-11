//
// Exercise 5-13.
//
// Write the program tail, which prints the last n lines of its input. By default, n is
// set to 10, let us say, but it can be changed by an optional argument so that
// `tail -n`
// prints the last n lines.
//
// The program should behave rationally no matter how unreasonable the input
// or the value of n. Write the program so it makes the best use of available storage; lines should be
// stored as in the sorting program of Section 5.6, not in a two-dimensional array of fixed size.
//
#include <stdio.h>

#define ARG_SIZE 3
#define SIZE_PARAM 1
#define MAX_LINES 5

int getln(char *line);

int main(int argc, char *argv[]) {
    printf("Program started \n");
    
    int tailArg = 0;
    
    char *p = argv[SIZE_PARAM];
    while (*p) {
        
        if (*p != '-')
            tailArg = tailArg * 10 + *p - '0';
        
        *p++;
    }
    
    if (tailArg > ARG_SIZE) {
        printf("Tail Argument is too big");
        return -1;
    }
    
    if (tailArg == 0) {
        printf("Nothing will be shown");
        return -1;
    }
    
    char* line[ARG_SIZE] = { NULL };
    
    int c;
    for (c = 0; c < ARG_SIZE; ++c)
        line[c] = malloc(10);
    
    int i;
    for (i = 0; i < ARG_SIZE && getln(line[i]) > 0; ++i)
        ;
    
    int last;
    for (last = ARG_SIZE - 1; last >= tailArg - 1; --last)
        printf("%s, \n", line[last]);
    
    
    printf("Program ended \n");
}

int getln(char *line) {
    
    int ch;
    int i = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        *line++ = ch;
        i++;
    }
    *line = '\0';
    
    return i;
}
