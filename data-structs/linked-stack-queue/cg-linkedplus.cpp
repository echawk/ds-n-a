#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string data;
    Node* next;

    Node* createNode(string, Node*);
    Node* findNode(string, Node*);
    void deleteNode(string, Node**);
    int listSize(Node*);
    void printList(Node*);
};

int Node::listSize(Node* n){
    Node* curr;
    int count = 0;
    for (curr = n; curr != NULL; curr = curr->next){
        count++;
    }
    return count;
}

Node* Node::createNode(string s, Node* n){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = s;
        newNode->next = n;
        return newNode;
}

Node* Node::findNode(string s, Node* n){
    Node* curr = n;
    if (n != NULL){
        while (curr->data != s){
            if (curr->next != NULL){
                curr = curr->next;
            }
        }
    }else{
        printf("This node does not exist!\n");
    }
    return curr;
}


void Node::deleteNode(string s, Node** n){
    Node* curr = *n;
    Node* prev = NULL;
    if (n != NULL){
        while (curr->data != s){
            if (curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }
        }
        if (curr == *n){
            *n = curr->next;
        }else{
            prev->next = curr->next;
        }
        free(curr);
    }else{
        printf("The list is empty!\n");
    }

}

void Node::printList(Node* n){
    while (n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
}

int main(){
    Node* temp;
    Node* sixth = temp->createNode("Manjaro", NULL);
    Node* fifth = temp->createNode("Ubuntu", sixth);
    Node* fourth = temp->createNode("Fedora", fifth);
    Node* third = temp->createNode("Arch", fourth);
    Node* second = temp->createNode("Mint", third);
    Node* head = temp->createNode("Debian", second);
    printf("Original list: ");
    head->printList(head);
    printf("\n");
    printf("\tList size: %d", head->listSize(head));
    head->deleteNode("Ubuntu", &head);
    printf("\nNew list: ");
    head->printList(head);
    printf("\n");
    printf("\tList size: %d", head->listSize(head));
    return 0;
}