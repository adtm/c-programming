//
//  4-3. Given the basic framework, it's straightforward to extend the calculator. Add the
//  modulus (%) operator and provisions for negative numbers.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define MAX_STACK_SIZE 10
#define NUMBER '0'

int getOp(char line[]);
void push(double);
double pop(void);

int main() {
    
    int type;
    double mainOp;
    char line[MAX_LENGTH];
    
    while ((type = getOp(line)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(line));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                mainOp = pop();
                push(pop() - mainOp);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                mainOp = pop();
                push(pop() / mainOp);
                break;
            case '%':
                mainOp = pop();
                push(fmod(pop(), mainOp));
                break;
            case '\n':
                printf("%f - final result \n", pop());
                return 0;
            default:
                printf("weird.. %c \n", type);
                break;
        }
    }
    
    return 0;
}

int stackFreeIndex = 0;
double stack[MAX_STACK_SIZE];

void push(double input) {
    
    if (stackFreeIndex < MAX_STACK_SIZE) {
        stack[stackFreeIndex++] = input;
    } else {
        printf("Stack Overflow!, %f", input);
    }
}

double pop() {
    
    if (stackFreeIndex > 0) {
        return stack[--stackFreeIndex];
    } else {
        printf("Stack Underflow!");
        return 0.0;
    }
}

int getOp(char line[]) {
    
    int ch;
    while((line[0] = ch = getch()) == ' ' || ch == '\t')
        ;
    line[1] = '\0';
    
    // will be an operator
    int idx = 0;
    if (!isdigit(ch) && ch != '-') return ch;
    
    ch = getchar();
    if (isdigit(ch)) {
        
        if (line[0] == '-') {
            line[++idx] = ch;
        }
        
        // wil be an operand
        while(isdigit(ch = getchar()))
            line[++idx] = ch;
        
        if (ch == '.')
            while(isdigit(ch = getchar()))
                line[++idx] = ch;
    }
    line[++idx] = '\0';
    
    return NUMBER;
}

