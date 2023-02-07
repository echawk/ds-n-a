//Nicholas Koeppen

#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
    int data;
    struct Data *next;
} *Node;

Node createNode(int d, Node n) {
    Node new = (Node)malloc(sizeof(struct Data));
    new->data = d;
    new->next = n;
    return new;
}

void addToBack(Node current, int data) {
    while (current != NULL) {
        current = current->next;
    }
    current->next = createNode(data, NULL);
}

void addToFront(Node head, int data) {
    Node new = (Node)malloc(sizeof(struct Data));
    new->next = head;
    head = new;
    new->data = data; 
}

void printList(Node current) {
    int i = 1;
    while (current != NULL) {
        printf("Data #%d: %d\n", i, current->data);
        current = current->next;
        i+=1; 
    }
}

int oldmain() {
    printf("%d\n", sizeof(Node*));
    printf("%d\n", sizeof(struct Data));
}

int main() {
    oldmain();
    Node head = createNode(1, NULL);

    printList(head);

    addToBack(head, 2);
    addToBack(head, 3);
    printList(head);
    return 0;
}