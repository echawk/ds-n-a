#!/usr/bin/env python3

from abc import ABC, abstractmethod


class Node:
    def __init__(self, data, link):
        self.data = data
        self.link = link


class LinkedList(ABC):
    def __init__(self, head_data):
        self.head = Node(head_data, None)

    @abstractmethod
    def put(self, data):
        pass

    @abstractmethod
    def pop(self):
        pass

    def length(self) -> int:
        current_node = self.head
        n = 0

        while current_node is not None:
            n += 1
            current_node = current_node.link

        return n

    def contains(self, data) -> bool:
        current_node = self.head

        while current_node is not None:
            if current_node.data == data:
                return True

            current_node = current_node.link

        return False

    def __str__(self) -> str:
        output = ""
        current_node = self.head

        while current_node is not None:
            output += current_node.data + " "
            current_node = current_node.link

        return output.rstrip()


class Queue(LinkedList):
    def put(self, data):
        node = Node(data, self.head)

        self.head = node

    def pop(self):
        current_node = self.head

        while current_node.link.link is not None:
            current_node = current_node.link

        data = current_node.link.data
        current_node.link = None

        return data


class Stack(LinkedList):
    def put(self, data):
        node = Node(data, self.head)

        self.head = node

    def pop(self):
        data = self.head.data
        self.head = self.head.link

        return data


def main():
    queue = Queue("fdsa")

    queue.put("asdf")
    queue.put("bvcx")
    queue.put("qwer")
    queue.put("poiu")

    print(queue)
    print(queue.length())

    print(queue.pop())

    print(queue)
    print(queue.length())

    stack = Stack("fdsa")

    stack.put("asdf")
    stack.put("bvcx")
    stack.put("qwer")
    stack.put("poiu")

    print(stack)
    print(stack.length())

    print(stack.pop())

    print(stack)
    print(stack.length())


if __name__ == "__main__":
    main()
