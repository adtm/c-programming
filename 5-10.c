//
//  Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the
//  command line, where each operator or operand is a separate argument. For example,
//
#include <stdio.h>

#define STACK_SIZE 20

void push(int param);

int main(int argc, char *argv[]) {
    
    char ch;
    while (--argc > 0) {
        ch = *(++argv)[0];
        
        switch (ch) {
            case '+': {
                int first = pop();
                int second = pop();
                push(first + second);
                break;
            }
            case '-': {
                int first = pop();
                int second = pop();
                push(second - first);
                break;
            }
            case '*': {
                int first = pop();
                int second = pop();
                push(first * second);
                break;
            }
            case '/': {
                int first = pop();
                int second = pop();
                push(second / first);
            }
            default: {
                int numberConvertion = ch - '0';
                if (0 <= numberConvertion && numberConvertion <= 9)
                    push(numberConvertion);
                else
                    printf("It's not a number!");
                break;
            }
        }
    }
    
    printf("%d final, \n", pop());
    return 0;
}

static int freeIndex = 0;
static int stack[STACK_SIZE];

void push(int param) {
    if (freeIndex < STACK_SIZE - 1)
        stack[freeIndex++] = param;
    else
        printf("Overflow!");
}

int pop() {
    if (freeIndex > 0)
        return stack[--freeIndex];
    else
        printf("Underflow!");
    return 0;
}

// 2 3 4 + *

// take char:
//  if it's number, put to stack
//  if it's a sign, pop two last numbers of the stack
//      - do sign logic and push to stack
//
// 2 3 4 +, 2 3 + 4, 2 7 *, 2 * 7 = 14
//
