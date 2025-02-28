#include <stdio.h>
#include <stdlib.h>
#define Max 10

int top = -1;
int stack[Max];

void push(int n){
    if(top >= Max-1){
        printf("Underflow");
    return ;
    }
    stack[++top] = n;
}

int pop(){
    if(top == -1){
        printf("Stack is empty");
    return 0; 
    }
    int x = stack[top];
    stack[top--];
    return x;
}
void printstack(){
    if(top == -1){
        printf("stack is empty");
        return ;
    }
    printf("The elements is the stack are:\n");
    for(int i=top;i>=0;i--){
        printf("[%d]",stack[i]);
    }
}
int peek(){
    if(top == -1){
        printf("empty");
    }
    return stack[top];
}
int main(){
    push(20);
    push(30);
    push(40);
    push(50);
    printf("%d is on the top\n",peek());
    printf("Popped element is %d\n",pop());
    
    printstack();
}
