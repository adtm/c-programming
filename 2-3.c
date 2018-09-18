//
//   2.3. Write a function htoi(s), which converts a string of hexadecimal digits (including
// an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a
// through f, and A through F.
//

#include <stdio.h>
#include <math.h>

enum constants {
    MAX_LIMIT = 1000,
    HEX = 16,
    FALSE = 0,
    TRUE = 1
};

int addByHex(int num, int power);
int readline(char to[]);
void cleanArray(char clean[]);

int main() {
    
    int length;
    char input[MAX_LIMIT];
    while ((length = readline(input)) && length > 0) {
        
        int i, sum = 0;
        int arr_length = length - 1;
        int till = 0;
        if (input[0] == '0') till += 2;
        
        for (i = arr_length; i >= till; --i) {
            int num = input[i];
            
            // check if digit
            if (num >= 0 && num <= 9) sum += addByHex(num, arr_length - i);
            
            // check if letter
            if ((num >= 'a' && num <= 'f') ||
                (num >= 'A' && num <= 'F')) {
                
                char letr = num;
                if (num >= 'A' && num <= 'F')
                    letr -= 'A';
                
                if (num >= 'a' && num <= 'f')
                    letr -= 'a';
                
                int num = (int) letr + 10;
                sum += addByHex(num, arr_length - i);
                
            } else {
                printf("There was an error in the input");
                break;
            }
        }
        printf("%d \n", sum);
    }
    
}

void cleanArray(char clean[]) {
    int i = 0;
    while(clean[i++] != '\0') clean[i] = '\0';
}

int readline(char save[]) {
    cleanArray(save);
    
    int i, ch;
    for (i = 0; i < MAX_LIMIT - 1 && (ch = getchar()) != EOF && ch != '\n'; ++i)
        save[i] = ch;
    
    return i;
}

int addByHex(int num, int power) {
    return num * (int) pow((double) HEX, (double) power);
}
