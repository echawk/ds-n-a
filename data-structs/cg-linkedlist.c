#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
};


void printList(struct Node* n){
    while (n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
}

int listSize(struct Node* n){
    struct Node* curr;
    int count = 0;
    for(curr = n; curr != NULL; curr = curr->next){
        count++;
    }
    return count;
}

/*function to create a node with data/link
 * and giving it a space in memory*/
struct Node* createNode(int d, struct Node *n){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->next = n;
    return newNode;
}

struct Node* findNode(int d, struct Node *n){
    struct Node* curr = n;
    if (n == NULL){
        return NULL;
    }
    while(curr->data != d){
        if(curr->next == NULL){
            return NULL;
        }else{
            curr = curr->next;
        }
    }
    return curr;
}


struct Node* deleteNode(int d, struct Node* n){
    struct Node* curr = n;
    struct Node* prev = NULL;
    if(n == NULL){
        return NULL;
    }
    while(curr->data != d){
        if(curr->next == NULL){
            return NULL;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
    if(curr == n){
        n = n->next;
    }else{
        prev->next = curr->next;
    }
    return curr;
}


int main(){
    struct Node* sixth = createNode(6, NULL);
    struct Node* fifth = createNode(5, sixth);
    struct Node* fourth = createNode(4, fifth);
    struct Node* third = createNode(3, fourth);
    struct Node* second = createNode(2, third);
    struct Node* head = createNode(1, second);
    printf("Original list: ");
    printList(head);
    printf("\tList size: %d", listSize(head));
    deleteNode(2, head);
    printf("\nNew list: ");
    printList(head);
    printf("\tList size: %d", listSize(head));
    return 0;
}
