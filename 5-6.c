//
//  5-6. Rewrite appropriate programs from earlier chapters and exercises with pointers
//  instead of array indexing. Good possibilities include [x]getline (Chapters 1 and 4), [x]atoi, [x]itoa, and
//  their variants (Chapters 2, 3, and 4), [x]reverse (Chapter 3), and [x]strindex and getop (Chapter 4).
//

#include <stdio.h>
#include <string.h>

#define LENGTH 5

int getLine(char *array);
void reverse(char *array);
int strIndex(char *source, char value);
void intToStr(int number, char *string);
int strToInt(char *array);

int main() {
    
    int number = 1234;
    char stringNumber[LENGTH];
    intToStr(number, stringNumber);
    
    char string[LENGTH] = "1234";
    printf("%d conversion", strToInt(string));
    
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

int strIndex(char *start, char value) {
    
    char *temp;
    temp = start;
    
    while(*start != '\0') {
        
        if (*start == value)
            return (int)(start - temp);
        
        *start++;
    }
    return -1;
}


void intToStr(int number, char *start) {
    
    char *end;
    end = start + strlen(start);
    
    int digit;
    while (number > 0) {
        digit = number % 10;
        *end-- = digit + '0';
        
        number = number / 10;
    }
}

int strToInt(char *start) {
    
    int num, *end;
    
    num = 0;
    end = start + strlen(start) - 1;
    
    while (start <= end) {
        int digit = *start - '0';
        num = num * 10 + digit;
        
        *start++;
    }
    
    return num;
}
