#include <iostream>
#include "cg-linkedplus.cpp"
using namespace std;

class Stack: public LinkedList{
public:
    LinkedList list;

    Stack(){
        list = LinkedList();
    }

    void push(int);
    void pop(Stack);
    int peek(Stack);
    int isEmpty(Stack);
    void printStack(Stack);
};

void Stack::push(int d){ LinkedList::addToFront(d); }
void Stack::pop(Stack s){ LinkedList::removeFirst(&s.head); }
int Stack::peek(Stack s){ return s.head->data; }
int Stack::isEmpty(Stack s){ return s.head == NULL; }
void Stack::printStack(Stack s){ LinkedList::printList(s.head); }


int main(){
    Stack s = Stack();
    srand((unsigned)time(NULL));
    //20 is how many items are in the queue
    for (int i = 0; i < 20; i++){
        s.push(rand() % 50);
    }
    printf("Here is the original stack: \n");
    s.printStack(s);
    //5 is how many items are being dequeued
    for (int j = 0; j < 5; j++){
        s.pop(s);
    }
    printf("\n\nHere is the modified stack: \n");
    s.printStack(s);
    return 0;
}