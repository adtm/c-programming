//
// 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in the
// string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and
// digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or
// trailing - is taken literally.
//

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

enum boolean {
    FALSE,
    TRUE
};

int main() {
    
    char line[MAX_LENGTH] = {'-', 'a','-','b','A','-','D','-','\0'};
    
    char min, max;
    int hasLine = FALSE;
    
    int i;
    for (i = 0; i < strlen(line); ++i) {
        char curr = line[i];
        char next = line[i + 1];
        
        // find the min
        if (!hasLine && curr != '-') {
            min = curr;
            hasLine = TRUE;
        }
        
        // termination case
        if ((curr != '-' && next != '-') || next == '\0') {
            int j;
            for (j = min; j <= max; ++j)
                printf("%c", j);
            
            hasLine = FALSE;
        }
        
        if (curr == '-' && next != '-')
            max = next;
    }
    
    return 0;
}
