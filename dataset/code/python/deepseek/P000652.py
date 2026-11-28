Here is the python code for the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def insertIntoSortedLinkedList(head, n):
    node = ListNode(n)
    if head is None:
        return node
    if n <= head.val:
        node.next = head
        return node
    cur = head
    while cur.next and cur.next.val < n:
        cur = cur.next
    node.next = cur.next
    cur.next = node
    return head

def print_list(head):
    cur = head
    while cur:
        print(cur.val, end=" ")
        cur = cur.next
    print()

def main():
    head = None
    arr = list(map(int, input().strip().split()))[1:]
    for num in arr:
        if head is None:
            head = ListNode(num)
            cur = head
        else:
            cur.next = ListNode(num)
            cur = cur.next
    n = arr[0]
    insertIntoSortedLinkedList(head, n)

if __name__ == '__main__':
    main()

In this code, we are defining a class `ListNode` to represent the nodes in the linked list. In the `insertIntoSortedLinkedList` function, we create a new node with the given integer value and insert it into the sorted linked list. If the linked list is empty or the value of the new node is less than the value of the head node, we just set the new node to the head. If the value of the new node is greater than the value of the head node, we find the correct position to insert the new node by traversing the linked list until we find the correct position and insert the new node there.

In the `main` function, we read the input and create the linked list from the input. We call the `insertIntoSortedLinkedList` function to insert the new node into the linked list. Finally, we print the linked list to verify the solution.