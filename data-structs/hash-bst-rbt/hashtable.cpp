#include <iostream>
#include <list>
using namespace std;

class HashTable {
  int capacity;
  list<int> *table;

public:
  HashTable(int c);
  void insert(int k, int d);
  void deleteNode(int k);
  void displayTable();

  int hashCode(int k) { return k % capacity; }

  int checkNum(int n) {
    if (n == 0 || n == 1) {
      return 0;
    }
    for (int i = 2; i < n / 2; i++) {
      if (n % i == 0) {
        return 0;
      }
    }
    return 1;
  }

  int getNum(int n) {
    if (n % 2 == 0) {
      n++;
    }
    while (!checkNum(n)) {
      n += 2;
    }
    return n;
  }
};

HashTable::HashTable(int c) {
  int size = getNum(c);
  this->capacity = size;
  table = new list<int>[capacity];
}

void HashTable::insert(int k, int d) {
  int i = hashCode(k);
  table[i].push_back(d);
}

void HashTable::deleteNode(int k) {
  int index = hashCode(k);
  list<int>::iterator i;
  for (i = table[index].begin(); i != table[index].end(); i++) {
    if (*i == k) {
      break;
    }
  }
  if (i != table[index].end()) {
    table[index].erase(i);
  }
}

void HashTable::displayTable() {
  for (int i = 0; i < capacity; i++) {
    cout << "table[" << i << "]";
    for (auto x : table[i])
      cout << " --> " << x;
    cout << endl;
  }
}

int main() {
  int key[] = {231, 321, 212, 321, 433, 262};
  int data[] = {123, 432, 523, 43, 423, 111};
  int size = sizeof(key) / sizeof(key[0]);

  HashTable h(size);

  for (int i = 0; i < size; i++)
    h.insert(key[i], data[i]);

  h.deleteNode(12);
  h.displayTable();
}