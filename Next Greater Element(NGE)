#include <stdio.h>
#include <stdlib.h>

#define size 100

int s[size];
int top = -1;

void push(int a){
    if(s[top]>=size-1){
        printf("Stack is Full");
        return ;
    }
    s[++top]=a;
    printf("\nPushed %d\n", a);
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

void nextgreatestelement(int a[],int n){
    int i,element,next;
    push(a[0]);
    for(i=1;i<n;i++){
    next = a[i];
    if(top != -1){
        element = pop();
    
    while(element<next){
        printf("%d is next greater to %d",next,element);
        if(top == -1){
            break;
        }
        element = pop();
    }
    if (element > next) {
        push(element);
    }
}
push(next);
}
   while (top != -1) {
        element = pop();
        next = -1;
        printf("%d --> %d\n", element, next);
    } 
}

int main(){
    int n = 6;
    int i = 0;
    int a[] = {1, 2, 3, 4, 5, 6};
    printf("Elements in the array are: ");
    for (i = 0; i < 6; i++) {
        printf("%d ", a[i]);
    }
    printf("\nThe next larger elements are: \n");
    nextgreatestelement(a, n);
    return 0;
}
