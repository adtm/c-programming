//
// 2-10. Rewrite the function lower, which converts upper case letters to lower case, with a
// conditional expression instead of if-else.
//

#include <stdio.h>

void toLower(char input[]);

int main() {
    
    char input[] = {'I', 'n', 'P', 'u','T', '\0'};
    
    printf("%s original \n", input);
    toLower(input);
    printf("%s modified \n", input);
    
    return 0;
}

void toLower(char input[]) {
    int i = 0;
    while(input[i++] != '\0') {
        input[i] = (input[i] >= 'A' && input[i] <= 'Z') ? input[i] - 'A' + 'a' : input[i];
    }
}
