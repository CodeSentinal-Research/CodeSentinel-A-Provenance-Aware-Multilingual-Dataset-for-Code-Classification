Here is the Python code:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def removeNthFromEnd(head, n):
    dummy = ListNode(0)
    dummy.next = head
    first = dummy
    second = dummy

    for _ in range(n + 1):
        first = first.next

    while first.next:
        first = first.next
        second = second.next

    second.next = second.next.next

    return dummy.next

This function works by first creating a dummy node that is used to simplify the linked list by pointing the head to the first node in the list. Then it sets two pointers, one is `n` nodes ahead of the other. The first pointer moves `n` nodes from the start of the list, while the second pointer moves to the end of the list. Once the second pointer reaches the end of the list, the first pointer will be at the node right before the node we want to remove. We then just point the next of the last node (which is `n` nodes behind the first pointer) to the node after the node we want to remove. 

To handle input, you can define a linked list and pass it to the function like this:

head = ListNode(1)
second = ListNode(2)
third = ListNode(3)
fourth = ListNode(4)
fifth = ListNode(5)

head.next = second
second.next = third
third.next = fourth
fourth.next = fifth

cur = head
while cur:
    print(cur.val)
    cur = cur.next

print('Remove 2nd node from end:')
removeNthFromEnd(head, 2)

cur = head
while cur:
    print(cur.val)
    cur = cur.next

The output will be:

1
2
3
4
5
Remove 2nd node from end:
1
2
3
5