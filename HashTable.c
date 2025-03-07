#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

struct Node {
    char *key;
    int value;
    struct Node *next;
} Node;

struct HashTable {
    Node **table;
} HashTable;

Node* createNode(char *key, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

unsigned int hash(char *key) {
    unsigned int hashValue = 0;
    while (*key) {
        hashValue = (hashValue << 5) + *key++;
    }
    return hashValue % TABLE_SIZE;
}

HashTable* createHashTable() {
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    hashTable->table = (Node **)malloc(TABLE_SIZE * sizeof(Node *));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

void insert(HashTable *hashTable, char *key, int value) {
    unsigned int index = hash(key);
    Node *newNode = createNode(key, value);
    
    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;
}

int search(HashTable *hashTable, char *key) {
    unsigned int index = hash(key);
    Node *current = hashTable->table[index];
    
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value; 
        }
        current = current->next;
    }
    return -1; 
}

void delete(HashTable *hashTable, char *key) {
    unsigned int index = hash(key);
    Node *current = hashTable->table[index];
    Node *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                hashTable->table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->key);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}
void freeHashTable(HashTable *hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = hashTable->table[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(hashTable->table);
    free(hashTable);
}

int main() {
    HashTable *hashTable = createHashTable();

    insert(hashTable, "key1", 1);
    insert(hashTable, "key2", 2);
    insert(hashTable, "key3", 3);

    printf("Value for 'key1': %d\n", search(hashTable, "key1"));
    printf("Value for 'key2': %d\n", search(hashTable, "key2"));
    printf("Value for 'key3': %d\n", search(hashTable, "key3"));
    printf("Value for 'key4': %d\n", search(hashTable, "key4")); 

    delete(hashTable, "key2");
    printf("Value for 'key2' after deletion: %d\n", search(hashTable, "key2")); 

    freeHashTable(hashTable);
    return 0;
}
