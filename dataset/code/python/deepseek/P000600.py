Sure, I'll write a Python solution for this problem.

We will have to create a Node class and a LinkedList class. The LinkedList class will have a method to reorder the linked list.

The Node class represents a node in the linked list.

The LinkedList class will have a method to create a linked list from an array.

Here is the Python code:

class Node:
    def __init__(self, x):
        self.val = x
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, x):
        if not self.head:
            self.head = Node(x)
        else:
            cur = self.head
            while cur.next:
                cur = cur.next
            cur.next = Node(x)

    def reorder(self):
        if not self.head or not self.head.next:
            return self.head

        odd_head = self.head
        even_head = self.head.next
        odd = odd_head
        even = even_head

        while odd and even:
            odd.next = even.next
            odd = odd.next
            even.next = odd.next
            even = even.next

        odd.next = even_head
        return odd_head


def main():
    linked_list = LinkedList()
    for i in [1, 2, 3, 4, 5]:
        linked_list.append(i)

    reordered_list = linked_list.reorder()

    while reordered_list:
        print(reordered_list.val, end=' ')
        reordered_list = reordered_list.next
    print()


if __name__ == "__main__":
    main()

In this code, we have a LinkedList class with a reorder method. In this method, we first separate the odd nodes and even nodes. Then we link the odd nodes to the even nodes and finally we link the remaining odd node to the rest of the even nodes.

In the main function, we create a linked list from an array and print the reordered linked list.