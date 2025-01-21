#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100


struct Stack {
    int top;
    char items[MAX_SIZE];
};


void initStack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        exit(EXIT_FAILURE);
    }
    s->items[++s->top] = c;
}


char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top--];
}

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    struct Stack stack;
    initStack(&stack);
    
    int i = 0; 
    int j = 0; 
    
    while (infix[i] != '\0') {
        char current = infix[i];
        
        if (isdigit(current) || isalpha(current)) {
            postfix[j++] = current;
        } else if (current == '(') {
            push(&stack, current);
        } else if (current == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); 
        } else { 
            while (!isEmpty(&stack) && precedence(stack.items[stack.top]) >= precedence(current)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, current);
        }
        
        i++;
    }
    
    
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    
    postfix[j] = '\0';
}

int main() {
char infix[MAX_SIZE], postfix[MAX_SIZE];
    
    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    
    infix[strcspn(infix, "\n")] = '\0';
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
   
    return 0;  
}
