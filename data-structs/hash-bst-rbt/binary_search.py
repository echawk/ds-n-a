#!/usr/bin/env python3


class Node:
    def __init__(self, data: int, left_link, right_link):
        self.data = data
        self.left_link = left_link
        self.right_link = right_link


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


def main():
    tree = BinarySearchTree(1)

    print(tree.get_all())
    print(tree)
    print(tree.length())

    tree.add(5)
    tree.add(3)
    tree.add(7)
    tree.add(2)

    # the result is sorted now, how fancy
    print(tree.get_all())
    print(tree)
    print(tree.length())

    print(tree.contains(5))
    print(tree.contains(9))

    print(tree.max())
    print(tree.min())


if __name__ == "__main__":
    main()
