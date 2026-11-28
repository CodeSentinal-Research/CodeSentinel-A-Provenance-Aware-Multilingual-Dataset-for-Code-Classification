Here is the Python code for the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def reverseKGroup(head, k):
    dummy = ListNode(0)
    dummy.next = head
    groupPrev = dummy
    while head:
        tail = getTail(head, k)
        if tail is None:
            break
        nextGroup = tail.next
        reverse(groupPrev, head, tail)
        groupPrev = tail
        head = nextGroup
    return dummy.next

def getTail(head, k):
    curr = head
    while k > 0 and curr:
        curr = curr.next
        k -= 1
    return curr

def reverse(groupPrev, start, end):
    prev, curr = end, start
    while prev != curr:
        next_node = curr.next
        curr.next = prev
        prev = curr
        curr = next_node
    start.next = prev
    return

def printList(head):
    while head:
        print(head.val, end=' ')
        head = head.next
    print()

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    k = 2
    printList(reverseKGroup(head, k))

    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    k = 3
    printList(reverseKGroup(head, k))

    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    k = 1
    printList(reverseKGroup(head, k))

main()

The main function calls the `reverseKGroup` function with different input values to test the code. It prints the reversed lists after each call.