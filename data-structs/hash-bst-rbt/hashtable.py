'''Author: Christian Garcia
Contents: Hash Table'''

import random

class HashNode:
    def __init__(self, key, data):
        self.key = key
        self.data = data
        self.link = None


class HashTable:

    hash_array: HashNode
    capacity: int
    size: int

    def __init__(self):
        self.capacity = 10
        self.size = 0
        self.hash_array = [None] * self.capacity

    def isEmpty(self):
        return (self.size() == 0)

    def hashCode(self, key):
        return key % self.capacity

    def getIndex(self, key: int):
        code = self.hashCode(key)
        index = code % self.capacity

    def insert(self, key, data):
        self.size += 1
        i = self.hashCode(key)        
        if self.hash_array[i] == None:
            self.hash_array[i] = HashNode(key, data)
        else:
            curr = self.hash_array[i]
            while curr.link != None:
                if curr.key == key:
                    curr.key = key
                    curr.data = data
                    return
                curr = curr.link
                curr.link = HashNode(key, data)

    def remove(self, key):
        self.size -= 1
        i = self.hashCode(key)
        curr = prev = self.hash_array[i]
        if not curr:
            return
        if curr.key == key:
            self.hash_array[i] = curr.link
        else:
            curr = curr.link
            while curr:
                if curr.key == key:
                    prev.link = curr.link
                    break
                else:
                    curr, prev = curr.link, prev.link

    def printTable(self):
        for i in range(self.capacity):
            if self.hash_array[i] == None:
                print("key:   | array[ ]:  ")
            else:    
                print("key: " + str(self.hash_array[i].key) + " | array[" + str(i) +"]: " + str(self.hash_array[i].data))


'''Main'''
hash_size = 0
hash_table = HashTable()
for i in range(hash_table.capacity):
    hash_table.insert(i, random.randint(1, 101))
print("The size of the hash table is: " + str(hash_table.size))
print("\nHere is the original table: ")
hash_table.printTable()
hash_table.remove(4)
print("\nThe size of the hash table is: " + str(hash_table.size))
print("\nHere is the modified table: ")
hash_table.printTable()                