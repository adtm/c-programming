//
// for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//      s[i] = c;
//
// 2.2 Write a loop equivalent to the for
// loop above without using && or ||.
//

#include <stdio.h>

#define MAX_LIMIT 100

int main() {
    
    int ch;
    char line[MAX_LIMIT];
    
    int i = 0;
    while(i < MAX_LIMIT - 1) {
        ch = getchar();
        
        if (!ch) break;
        if (ch == '\n') break;
        
        line[i] = ch;
        ++i;
    }
    
    printf("%s \n", line);
    return 0;
}
