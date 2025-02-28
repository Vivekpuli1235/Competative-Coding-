#include<stdio.h>
#include<stdlib.h>

struct lstack{
	int data;
	struct lstack*next;
};

struct lstack* head = NULL;

struct lstack* createnode(int data){
	struct lstack*Newnode = (struct lstack*)malloc(sizeof(struct lstack));
	Newnode->data = data;
	Newnode->next = NULL;
	return Newnode;
}

struct lstack* addontop(int data){
	struct lstack* Newnode = createnode(data);
	    Newnode->next = head;
		head = Newnode ;
		printf("Added on top;\n");
	}
void display(){
	struct lstack* current = head;
	if(head == NULL){
		printf("No elements");
		return;
	}else{
		while(current != NULL){
			printf("~%d",current->data);
			current = current->next;
		}
	}
}

void topele(){
	struct lstack* current = head;
	printf("\nTop Element is = %d",current->data);
}
int main(){
  addontop(10);
  addontop(20);	
  addontop(30);
  display();
  topele();
  return 0;
}
