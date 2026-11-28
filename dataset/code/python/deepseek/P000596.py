Here's the Python code for sorting a singly linked list using the merge sort algorithm.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def sortList(head):
    if not head or not head.next:
        return head

    slow, fast = head, head.next
    prev_slow, slow = None, slow.next
    while fast and fast.next:
        fast = fast.next.next
        prev_slow = slow
        slow = slow.next

    second = prev_slow.next
    prev_slow.next = None

    l1 = sortList(head)
    l2 = sortList(second)

    sorted_list = merge(l1, l2)
    return sorted_list

def merge(l1, l2):
    if not l1:
        return l2
    if not l2:
        return l1

    head = None
    if l1.val < l2.val:
        head = l1
        l1 = l1.next
    else:
        head = l2
        l2 = l2.next

    curr = head
    while l1 and l2:
        if l1.val < l2.val:
            curr.next = l1
            l1 = l1.next
        else:
            curr.next = l2
            l2 = l2.next
        curr = curr.next

    if l1:
        curr.next = l1
    if l2:
        curr.next = l2

    return head

For the input handling part, you can use the following code:

def create_linked_list(nums):
    head = None
    curr = None
    for num in nums:
        if not head:
            head = ListNode(num)
            curr = head
        else:
            curr.next = ListNode(num)
            curr = curr.next
    return head

def print_linked_list(head):
    curr = head
    while curr:
        print(curr.val, end=" ")
        curr = curr.next
    print()

nums = [5, 1, 4, 3, 2, 0]
head = create_linked_list(nums)
print_linked_list(head)
sorted_head = sortList(head)
print_linked_list(sorted_head)

This code first creates a linked list from a list of numbers, then sorts it using the `sortList` function, and finally prints the sorted list. The `create_linked_list` and `print_linked_list` functions are used for input handling.