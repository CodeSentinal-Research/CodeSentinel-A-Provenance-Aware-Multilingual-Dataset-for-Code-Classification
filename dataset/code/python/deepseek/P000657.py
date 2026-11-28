Here is a Python code snippet that sorts a bitonic doubly linked list.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

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
            new_node = Node(data)
            cur.next = new_node
            new_node.prev = cur

    def print_list(self):
        cur = self.head
        while cur:
            print(cur.data, end = ' ')
            cur = cur.next
        print()

def sorted_doubly_linked_list(head):
    if head is None or head.next is None:
        return head

    slow = head
    fast = head
    prev_mid_prev = None
    while fast and fast.next:
        fast = fast.next.next
        prev_mid_prev = slow
        slow = slow.next

    mid_node = slow
    if prev_mid_prev:
        prev_mid_prev.next = None

    left_half = sorted_doubly_linked_list(head)
    right_half = sorted_doubly_linked_list(mid_node)

    sorted_list = merge(left_half, right_half)

    return sorted_list

def merge(l1, l2):
    if not l1:
        return l2
    if not l2:
        return l1

    if l1.data < l2.data:
        l1.next = merge(l1.next, l2)
        l1.next.prev = l1
        l1.prev = None
        return l1
    else:
        l2.next = merge(l1, l2.next)
        l2.next.prev = l2
        l2.prev = None
        return l2

def main():
    dll = DoublyLinkedList()
    nums = [3, 6, 7, 10, 1, 2, 7, 3]
    for num in nums:
        dll.append(num)

    sorted_list = sorted_doubly_linked_list(dll.head)
    dll.head = sorted_list

    dll.print_list()

if __name__ == "__main__":
    main()

This program first finds the mid point of the list, then splits the list into two halves at the mid point, and finally merges the two sorted halves to form a sorted list.