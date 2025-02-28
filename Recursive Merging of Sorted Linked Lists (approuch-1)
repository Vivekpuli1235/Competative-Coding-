#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *sortedMerge(struct Node *head1, struct Node *head2) {
  
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    if (head1->data <= head2->data) {
        head1->next = sortedMerge(head1->next, head2);
        return head1;
    }
    else {
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
}
void printList(struct Node *curr) {
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL) {
            printf(" ");
        }
        curr = curr->next;
    }
    printf("\n");
}

struct Node *createNode(int data) {
    struct Node *newNode = 
      (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node *head1 = createNode(6);
    head1->next = createNode(5);
    head1->next->next = createNode(15);
    struct Node *head2 = createNode(1);
    head2->next = createNode(8);
    head2->next->next = createNode(20);

    struct Node *res = sortedMerge(head1, head2);

    printList(res);

    return 0;
}
