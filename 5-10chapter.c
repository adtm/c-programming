//
//  Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the
//  command line, where each operator or operand is a separate argument. For example,
//

#include <stdio.h>
#include <string.h>

#define LINE_MAX 100

int getrow(char *line, int limit);

int main(int argc, char *argv[]) {
    printf("Start off program \n");
    
    int numbering = -1;
    int invert = -1;
    
    int ch;
    while (--argc > 0 && (*++argv)[0] == '-') {
        while (ch = *++argv[0]) {
            switch (ch) {
                case 'n':
                    numbering = 1;
                    break;
                case 'x':
                    invert = 1;
                    break;
                default:
                    printf("Illegal option: %c\n", ch);
                    argc = 0;
                    break;
            }
        }
    }
    
    int found = 0;
    char line[LINE_MAX];
    
    if (argc != 1)
        printf("Find Pattern: argument for search value");
    else
        while (getrow(line, LINE_MAX) > 0)
            if ((strstr(line, *argv) != NULL) != invert) {
                printf("%s: %s, in: %s \n", invert == 0 ? "Found" : "Not-found" ,*argv, line);
                found++;
            }
    
    printf("End off program \n");
    return 0;
}

int getrow(char *line, int limit) {
    
    int c, i;
    for (i = 0; i < limit && ((c = getchar()) != EOF) && c != '\n'; i++)
        *(line)++ = c;
    
    return i;
}
