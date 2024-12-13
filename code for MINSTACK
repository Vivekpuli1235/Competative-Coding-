#include <stdio.h>
#include <stdlib.h>
#define size 100

int top = -1;
int s[size];
int minStack[size];

void push(int a){
    if(s[top]>=size-1){
        printf("Stack is Full");
        return ;
    }
    s[++top]=a;
    if (top == 0 || a <= minStack[top - 1]) 
    {
        minStack[top] = a;
    } 
    else 
    {
        minStack[top] = minStack[top - 1]; 
    }
    
    printf("Pushed %d\n", a);
}

int pop(){
    if(top ==-1){
        printf("Stack is empty");
        return -1;
    }
    else{
        int x = s[top--];
        return x;
    }
}
int getMin() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1; 
    }
    return minStack[top]; 
}

void printstack(){
    int i;
    if(top ==-1){
        printf("Stack is empty");
        return;
    }
        for(i=top;i>=0;i--){
        printf("[%d]",s[i]);
    }
    printf("\n");
    }
int main(){
    push(10);
    push(20);
    push(5);
    push(15);
    
    printstack();
    
    printf("Current Minimum: %d\n", getMin());
    
    pop();
    printstack();
    
    printf("Current Minimum: %d\n", getMin());
}
