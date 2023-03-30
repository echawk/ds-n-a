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

    def __len__(self) -> int:
        current_node = self.head
        n = 0

        while current_node is not None:
            n += 1
            current_node = current_node.link

        return n

    def __contains__(self, data) -> bool:
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


class PriorityNode:
    def __init__(self, data, link):
        self.data = data
        self.link = link


class PriorityQueue:
    def __init__(self, head_data):
        self.head = []
        self.head.append(PriorityNode(head_data, None))

    def put(self, data, priority: int):
        # a node already exists with that priority
        if 0 <= priority < len(self.head):
            self.head[priority] = PriorityNode(data, self.head[priority])
        # a node does not exist with that priority and the priority increases by 1
        elif priority == len(self.head):
            self.head.append(PriorityNode(data, None))
        else:
            # this is due to the constraints of the list in Python
            raise Exception("Priority cannot be raised by more than 1")

    def pop(self):
        for priority, head in enumerate(self.head):
            if head is not None:
                if head.link is None:
                    data = head.data
                    self.head[priority] = None
                    return data

                current_node = head
                previous_node = None

                while current_node.link is not None:
                    previous_node = current_node
                    current_node = current_node.link

                previous_node.link = None
                data = current_node.data

                return data

    def __len__(self) -> int:
        n = 0

        for head in self.head:
            current_node = head
            while current_node is not None:
                n += 1
                current_node = current_node.link

        return n

    def count_of_priority_levels(self) -> int:
        return len(self.head)

    def contains(self, data) -> (bool, int, PriorityNode):
        for priority, head in enumerate(self.head):
            current_node = head
            while current_node is not None:
                if current_node.data == data:
                    return True, priority, current_node

                current_node = current_node.link

        return False, -1, None

    def __contains__(self, data) -> bool:
        contained, _, _ = self.contains(data)
        return contained

    def __str__(self) -> str:
        output = ""

        for priority, head in enumerate(self.head):
            current_node = head
            output += "Priority " + str(priority) + ": "

            while current_node is not None:
                output += str(current_node.data) + " "
                current_node = current_node.link

            output += "\n"

        return output.rstrip()


def main():
    queue = Queue("fdsa")

    queue.put("asdf")
    queue.put("bvcx")
    queue.put("qwer")
    queue.put("poiu")

    print(queue)
    print(len(queue))

    print(queue.pop())

    print(queue)
    print(len(queue))

    stack = Stack("fdsa")

    stack.put("asdf")
    stack.put("bvcx")
    stack.put("qwer")
    stack.put("poiu")

    print(stack)
    print(len(stack))

    print(stack.pop())

    print(stack)
    print(len(stack))

    print("PRIORITY QUEUE")

    priority_queue = PriorityQueue(5)

    print(len(priority_queue))
    print(priority_queue)

    priority_queue.put(4, 0)
    priority_queue.put(7, 0)

    print(priority_queue.count_of_priority_levels())
    print(len(priority_queue))
    print(priority_queue)

    print(priority_queue.contains(4))
    print(4 in priority_queue)

    print(priority_queue.pop())

    print(priority_queue)

    priority_queue.put(9, 1)

    print(priority_queue.count_of_priority_levels())
    print(priority_queue)

    print(priority_queue.pop())
    print(priority_queue.pop())
    print(priority_queue.pop())
    print(priority_queue)


if __name__ == "__main__":
    main()
