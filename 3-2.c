//
// 3.2 Write a function escape(s,t) that converts characters like newline and tab into
// visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
// function for the other direction as well, converting escape sequences into the real characters.
//

#include <stdio.h>

#define MAX_LENGTH 20

void toEscape(char from[], char to[]);
void fromEscape(char from[], char to[]);
void clearArray(char input[]);

int main() {
    
    char from_one[MAX_LENGTH] = {'d', 'o', '\n', '\t', 'g', '\0'};
    char to_one[MAX_LENGTH];
    clearArray(to_one);
    
    printf("%s, before escape \n", from_one);
    toEscape(from_one, to_one);
    printf("%s, after escape \n", to_one);
    
    printf("\n");
    
    char from_two[MAX_LENGTH] = {'d', 'o', '\\', 'n', 'g', '\0'};
    char to_two[MAX_LENGTH];
    clearArray(to_two);
    
    printf("%s, before escape \n", from_two);
    fromEscape(from_two, to_two);
    printf("%s, after escape \n", to_two);
    
    return 0;
}

void clearArray(char input[]) {
    int i;
    for (i = 0; i < MAX_LENGTH; ++i)
        input[i] = '\0';
}

void toEscape(char from[], char to[]) {
    
    int i, j;
    i = j = 0;
    
    while(from[i] != '\0') {
        switch (from[i]) {
            case '\n': {
                to[j++] = '\\';
                to[j++] = 'n';
                break;
            };
            case '\t': {
                to[j++] = '\\';
                to[j++] = 't';
                break;
            }
            default:
                to[j++] = from[i];
                break;
        }
        i++;
    }
}

void fromEscape(char from[], char to[]) {
    
    int i, j;
    i = j = 0;
    
    while(from[i] != '\0') {
        switch (from[i]) {
            case '\\': {
                switch (from[++i]) {
                    case 'n':
                        to[j++] = '\n';
                        break;
                    case 't':
                        to[j++] = '\t';
                        break;
                    default:
                        break;
                }
                break;
            };
            default:
                to[j++] = from[i];
                break;
        }
        printf("%s orgiinal \n", to);
        i++;
    }
}
