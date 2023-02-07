#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node *next;
}*node;

//typedef struct Node* node;

void printList(node n){
    while (n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
}

int listSize(node n){
    node curr;
    int count = 0;
    for(curr = n; curr != NULL; curr = curr->next){
        count++;
    }
    return count;
}

/*function to create a node with data/link
 * and giving it a space in memory*/
node createNode(int d, node n){
    node newNode;
    newNode = (node)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = n;
    return newNode;
}

node findNode(int d, node n){
    node curr = n;
    if (n != NULL){
        while(curr->data != d){
            if(curr->next != NULL){
                curr = curr->next;
            }
        }
    }else{
        printf("This node does not exist!\n");
    }
    return curr;
}


void deleteNode(int d, node n){
    node curr = n;
    node prev = NULL;
    if(n != NULL){
        while(curr->data != d){
            if(curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }
        }
        if(curr == n){
            n = n->next;
        }else{
            prev->next = curr->next;
        }
    }else{
        printf("The list is empty!\n");
    }
}

/*
int main(){
    node sixth = createNode(6, NULL);
    node fifth = createNode(5, sixth);
    node fourth = createNode(4, fifth);
    node third = createNode(3, fourth);
    node second = createNode(2, third);
    node head = createNode(1, second);
    printf("Original list: ");
    printList(head);
    printf("\n");
    //printf("\tList size: %d", listSize(&head));
    printf("\nNew list: ");
    printList(head);
    printf("\tList size: %d", listSize(head));
    return 0;
}*/
