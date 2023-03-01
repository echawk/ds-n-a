#!/usr/bin/env python3.9

from typing import Optional


class Node:
    def __init__(self, data: int, left_link, right_link):
        self.data = data
        self.left_link = left_link
        self.right_link = right_link

    def depth_first_search_helper(self, data: int):
        if self.left_link is not None:
            result = self.left_link.depth_first_search_helper(data)

            if result is not None:
                return result

        if self.right_link is not None:
            result = self.right_link.depth_first_search_helper(data)

            if result is not None:
                return result

        if self.data == data:
            return self

        return None

    def breadth_first_search_helper(self, data: int):
        if self.data == data:
            return self

        if self.left_link is not None:
            result = self.left_link.breadth_first_search_helper(data)

            if result is not None:
                return result

        if self.right_link is not None:
            result = self.right_link.breadth_first_search_helper(data)

            if result is not None:
                return result

        return None


class BinarySearchTree:
    def __init__(self, head_data: int):
        self.head = Node(head_data, None, None)

    def __insert_into_tree(self, data: int, link: Node) -> Node:
        if link is None:
            return Node(data, None, None)
        elif data < link.data:
            link.left_link = self.__insert_into_tree(data, link.left_link)
        else:
            link.right_link = self.__insert_into_tree(data, link.right_link)

        return link

    def add(self, data: int):
        self.head = self.__insert_into_tree(data, self.head)

    def __contains_in_tree(self, data: int, link: Node) -> bool:
        if link is None:
            return False
        elif link.data == data:
            return True
        elif data < link.data:
            return self.__contains_in_tree(data, link.left_link)
        else:
            return self.__contains_in_tree(data, link.right_link)

    def contains(self, data: int) -> bool:
        return self.__contains_in_tree(data, self.head)

    def __all_elements_in_tree(self, link: Node) -> list:
        if link is None:
            return []
        else:
            tree = self.__all_elements_in_tree(link.left_link)
            tree.append(link.data)
            tree.extend(self.__all_elements_in_tree(link.right_link))

            return tree

    def get_all(self) -> list:
        return self.__all_elements_in_tree(self.head)

    def __str__(self) -> str:
        return " ".join(map(str, self.get_all()))

    def min(self) -> int:
        current_node = self.head

        while current_node.left_link is not None:
            current_node = current_node.left_link

        return current_node.data

    def max(self) -> int:
        current_node = self.head

        while current_node.right_link is not None:
            current_node = current_node.right_link

        return current_node.data

    def __length_of_tree(self, link: Node) -> int:
        if link is None:
            return 0
        else:
            return (
                self.__length_of_tree(link.left_link)
                + self.__length_of_tree(link.right_link)
                + 1
            )

    def length(self) -> int:
        return self.__length_of_tree(self.head)

    def depth_first_search(self, data: int) -> Optional[Node]:
        return self.head.depth_first_search_helper(data)

    def breadth_first_search(self, data: int) -> Optional[Node]:
        return self.head.breadth_first_search_helper(data)


def main():
    tree = BinarySearchTree(1)

    tree.add(5)
    tree.add(3)
    tree.add(7)
    tree.add(2)
    tree.add(14)
    tree.add(8)
    tree.add(1)
    tree.add(3)
    tree.add(9)

    node = tree.breadth_first_search(4)

    if node is not None:
        print(node.data)
    else:
        print("NO!")


if __name__ == "__main__":
    main()
