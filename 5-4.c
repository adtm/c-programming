//
//  5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the end of
//  the string s, and zero otherwise.
//
#include <stdio.h>
#include <string.h>

#define LENGTH 100
enum boolean {
    FALSE,
    TRUE
};

int strend(char *f, char *s);

int main() {
    
    char first[LENGTH] = "this_is_text";
    char second[LENGTH] = "texts";
    
    int result = strend(first, second);
    printf("%d \n", result);
    
    return 0;
}

int strend(char *f, char *s) {
    
    int s_len = (int) strlen(s);
    
    while(*f != '\0')
        f++;
    
    while (*s != '\0')
        s++;
    
    int i;
    for (i = 0; i < s_len; ++i, --s, --f)
        if (*s != *f)
            return FALSE;
    
    return TRUE;
}
