#include <stdio.h>
#define size 10
int q[size];
int f = -1;
int r = -1;
int enque(int data){
    if(r>=size-1){
        printf("FULL");
    }else if(f == -1 && r == -1){
        f = r = 0;
               q[r]=data;
        printf("%d is enqued\n",q[r]);
 
    }else{
        r++;
        q[r]=data;
        printf("%d is enqued\n",q[r]);
    }
    return r;
}
int deque(){
    if(f==-1){
        printf("EMPTY");
        return f;
    }
    else{
        int x = q[f];
        printf("%d is dequed\n",x);
        if(f == r){
            f = r = -1;
        }
        else{
            f++;}
    } return f;}
void display(){
    if(f == -1 || f > r ){
        printf("EMPTY");
    }
    else{
        for(int i=f;i<=r;i++){
            printf("[%d]\t",q[i]);
        }
    }
}

int main(){
    enque(10);
    enque(20);
    enque(30);
    display(f,r);
    printf("\n");
    deque();
}
