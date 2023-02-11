/*Author: Christian Garcia
Contents: Hash Table*/


#include <stdio.h>
#include <stdlib.h>


typedef struct hashTable{
    int key;
    int data;
} hash;

hash *array;
int size = 0;
int capacity = 10;

int hashCode(int k){ return k % capacity; }
int hashSize(){ return size; }

int checkNum(int n){
    if (n == 0 || n == 1){
        return 0;
    }
    for (int i = 2; i < n/2; i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

int getNum(int n){
    if (n % 2 == 0){
        n++;
    }
    while(!checkNum(n)){
        n += 2;
    }
    return n;
}

void init(){
    capacity = getNum(capacity);
    array = (hash*)malloc(capacity * sizeof(hash));
    for(int i = 0; i < capacity; i++){
        array[i].key = 0;
        array[i].data = 0;
    }
}

void insert(int d, int k){
    int i = hashCode(k);
    if (array[i].data == 0){
        array[i].key = k;
        array[i].data = d;
        size++;
    }else if (array[i].key == k){
        array[i].data = d;
    }
}

void removeValue(int k){
    int i = hashCode(k);
    if (array[i].data != 0){
        array[i].key = 0;
        array[i].data = 0;
        size--;
    }
}

void printTable(){
    for(int i = 0; i < capacity; i++){
        if(array[i].data == 0){
            printf("\nkey:   | array[ ]:  \t");
        }else{
            printf("\nkey: %d | array[%d]: %d \t", array[i].key, i, array[i].data);
        }
    }
}

int main(){
    init();
    for (int i = 0; i < capacity; i++){
        insert(rand() % 101, i);
    }
    printf("The size of the hash table is: %d\n", hashSize());
    printf("Here is the original table: ");
    printTable();
    removeValue(4);
    printf("\n\nHere is the modified table: ");
    printTable();
    return 0;
}
