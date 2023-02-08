//Nicholas Koeppen
#include <stdio.h>
#include <stdlib.h>
#include "nk-linkedlist.c"

void add(Node* current, int newData) { //Adds to back
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = createNode(newData, NULL);
}

int rem(Node* head) { //Removes from front
    if (head == NULL) {
        return -1;
    } else {
        int x = head->data;
        Node* temp = head;
        head = head->next;
        //free(temp);
        return(x);
    }
}

int main() {
    Node* head = createNode(1, NULL);
    add(head, 2);
    add(head, 3);
    add(head, 4);
    printList(head);

    printf("Removed first element, number stored was %d\n", rem(head));
    printList(head);

    printf("Removed first element Mach II\n");
    head = head->next;
    printList(head);
}
