Sure, here is the Python code for converting a sorted doubly linked list into a height-balanced Binary Search Tree.

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            cur = self.head
            while cur.next:
                cur = cur.next
            cur.next = Node(data)
            cur.next.prev = cur


def sorted_doubly_linked_list_to_bst(head):
    if not head:
        return None
    if not head.next:
        return head

    slow = head
    fast = head.next

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    temp = slow.next
    slow.next = None
    temp.prev = None

    bst = Node(slow.data)
    bst.left = sorted_doubly_linked_list_to_bst(head)
    bst.right = sorted_doubly_linked_list_to_bst(temp)

    return bst


def print_bst(root):
    if root:
        print(root.data, end=' ')
        print_bst(root.left)
        print_bst(root.right)


def main():
    n = int(input().strip())
    linked_list = DoublyLinkedList()
    for i in range(n):
        linked_list.append(int(input().strip()))

    root = sorted_doubly_linked_list_to_bst(linked_list.head)
    print_bst(root)


if __name__ == "__main__":
    main()
This code first reads the number of elements in the doubly linked list and then the elements themselves. The elements are stored in the doubly linked list in the input. The sorted doubly linked list is then converted to a height-balanced Binary Search Tree (BST) using the `sorted_doubly_linked_list_to_bst` function. The BST is then printed using the `print_bst` function.