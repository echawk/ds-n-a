//Nicholas Koeppen

#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
    int data;
    struct Data* leftChild;
    struct Data* rightChild;
} Node;

Node* insert(Node* current, int insert) {
    Node* tempNode = (Node*)malloc(sizeof(Node));
    Node* parent = NULL;

    tempNode->data = insert;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    if (current == NULL) { //empty tree
        current = tempNode;
        return current;
    } else {
        while (1) {
            parent = current;

            if (insert == current->data) { //Node is already in tree
                return current;
            } else if (insert < current->data) { //Go to left child
                current = current->leftChild;
                
                if (current == NULL) {
                    parent->leftChild = tempNode;
                    return parent->leftChild;
                }
            } else { //Go to right child
                current = current->rightChild;

                if (current == NULL) {
                    parent->rightChild = tempNode;
                    return parent->rightChild;
                }
            }
        }
    }
}

Node* search(Node* current, int find) {
    while (current->data != find) {
        if (current != NULL) {
            if (current->data > find) { //Go to left child
                current = current->leftChild;
            } else { //Go to right child
                current = current->rightChild;
            }
            
            if(current == NULL) {
                return NULL;
            }
        }
    }
    return current;
}

void rebalance(Node* head, Node* current) {
    if (current != NULL) {
        insert(head, current->data);
        rebalance(head, current->leftChild);
        rebalance(head, current->rightChild);
    }
}

int delete(Node* head, int delete) {
    Node* current = head;
    while (current->leftChild->data != delete && current->rightChild->data != delete) { //Gets parent node of delete 
        if (current != NULL) {
            if (current->data > delete) { //Go to left child
                current = current->leftChild;
            } else { //Go to right child
                current = current->rightChild;
            }
            
            if(current == NULL) {
                return -1;
            }
        }
    }
    printf("Found node");

    Node* deleteHead; 
    if (current->leftChild->data == delete) { //Makes delete sub-tree so that its children can be rebalanced
        deleteHead = current->leftChild;
        current->leftChild = NULL;
    } else {
        deleteHead = current->rightChild;
        current->rightChild = NULL;
    }
    
    if (deleteHead->leftChild != NULL) { //Rebalances tree
        rebalance(head, deleteHead->leftChild);
    }
    if (deleteHead->rightChild != NULL) {
        rebalance(head, deleteHead->rightChild);
    }

    free(deleteHead);
    return 0;
}

void printTree(Node* root, int level) { //From Stack Overflow
        if (root == NULL) {
                return;
        }
        for (int i = 0; i < level; i++) {
                printf(i == level - 1 ? "  |-" : "    ");
        }
        printf("(%d)\n", root->data);
        printTree(root->leftChild, level + 1);
        printTree(root->rightChild, level + 1);
}

int main() {
    Node* root = insert(NULL, 14);
    //printf("%d\n", root->data);
    insert(root, 14);
    insert(root, 20);
    insert(root, 10);
    insert(root, 21);
    insert(root, 22);
    insert(root, 4);
    printf("Here");
    //printf("%d\n", root->leftChild->data);
    //printf("%d\n", root->rightChild->data);
    printTree(root, 0);
    printf("Here");
    delete(root, 21);
    printTree(root, 0);
}