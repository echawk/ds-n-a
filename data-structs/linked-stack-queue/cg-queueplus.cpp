#include <iostream>
#include "cg-linkedplus.cpp"
using namespace std;

class Queue : public LinkedList{
public:
    LinkedList list;

    Queue(){
        list = LinkedList();
    }

    void addToQueue(int);
    void removeFromQueue(Queue);
    void printQueue(Queue);
};

void Queue::addToQueue(int n){
    LinkedList::addToEnd(n);
}

void Queue::removeFromQueue(Queue q){
    LinkedList::removeFirst(&q.head);
}

void Queue::printQueue(Queue q){
    Node *node = q.head;
    LinkedList::printList(node);
}

int main(){
    Queue q = Queue();
    srand((unsigned)time(NULL));
    //20 is how many items are in the queue
    for (int i = 0; i < 20; i++){
        q.addToQueue(rand() % 50);
    }
    printf("Here is the original queue: \n");
    q.printQueue(q);
    //5 is how many items are being dequeued
    for (int j = 0; j < 5; j++){
        q.removeFromQueue(q);
    }
    printf("\n\nHere is the modified queue: \n");
    q.printQueue(q);
    return 0;
}