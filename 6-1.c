#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD 100
#define KEY_COUNT 3

struct key {
    char *word;
    int count;
} keyArr[] = {
    "a", 0,
    "b", 0,
    "c", 0
};

int getword(char*, int limit);
int binSearch(char *, struct key tab[], int limit);


int main(int argc, char *argv[]) {
    printf("Program starting! \n");
    
    
    int idx;
    char word[MAX_WORD];
    
    while (getword(word, MAX_WORD) != EOF) {
        if ((idx = binSearch(word, keyArr, KEY_COUNT)) >= 0) {
            keyArr[idx].count++;
        }
        for (idx = 0; idx < KEY_COUNT; ++idx)
            printf("%4d %s, ", keyArr[idx].count, keyArr[idx].word);
        printf("\n");
    }
    
    printf("Program ending! \n");
}

// for proper handling would use
// ungetch and getch
int getword(char *word, int limit) {
    
    char ch;
    char *w = word;
    
    while(isspace(ch = getchar()))
        ;
    
    if (ch != EOF)
        *w++ = ch;
    
    if (!isalpha(ch)) {
        *w = '\0';
        return ch;
    }
    
    while (--limit > 0)
        if (!isalnum(*w++ = getchar()))
            break;
    
    *--w = '\0';
    return word[0];
}

int binSearch(char *word, struct key tab[], int keyLimit) {
    
    int start = 0;
    int end = keyLimit - 1;
    
    int cond;
    while (start <= end) {
        
        int mid = (start + end) / 2;
        if ((cond = strcmp(word, tab[mid].word)) == 0)
            return mid;
        else if (cond < 0)
            end = end - 1;
        else
            start = start + 1;
        
    }
    return -1;
}
