//
//  5-6. Rewrite appropriate programs from earlier chapters and exercises with pointers
//  instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa, and
//  their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop (Chapter 4).
//

#include <stdio.h>
#include <string.h>

#define LENGTH 5

int getLine(char *array);
void reverse(char *array);

int main() {
    
    char arr[LENGTH] = "abcd";
    reverse(arr);
    
    return 0;
}

int getLine(char *arr) {
    char *p;
    p = arr;
    
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        *arr++ = ch;
    }
    
    return (int)(arr - p);
}

void reverse(char *start) {
    
    char *end, temp;
    
    end = start + strlen(start) - 1;
    
    while (start < end) {
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
    
}
