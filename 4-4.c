//
//  4-4. Add the commands to print the top elements of the stack without popping, to
//  duplicate it, and to swap the top two elements. Add a command to clear the stack.
//

#include <stdio.h>

#define STACK_LENGTH 100

int currentIndex = 0;
int stack[STACK_LENGTH];

int pop(void);
void push(int num);
void peek(void);
void swapTop(void);
void clearStack(void);

int main() {
    
    push(1);
    push(2);
    push(3);
    push(4);
    
    peek();
    
    swapTop();
    
    clearStack();
    
    return 0;
}

void peek(void) {
    printf("top: %d", stack[currentIndex - 1]);
}

void push(int num) {
    if (currentIndex >= STACK_LENGTH)
        printf("Stack Overflow! \n");
    else
        stack[currentIndex++] = num;
}

void swapTop(void) {
    int temp = stack[currentIndex - 2];
    stack[currentIndex - 2] = stack[currentIndex - 1];
    stack[currentIndex - 1] = temp;
}

void clearStack(void) {
    int i;
    for (i = 0; i <= currentIndex; ++i)
        stack[i] = '\0';
}

int pop(void) {
    if (currentIndex > 0)
        return stack[currentIndex--];
    else
        printf("Stack Underflow! \n");
    
    return 0;
}

