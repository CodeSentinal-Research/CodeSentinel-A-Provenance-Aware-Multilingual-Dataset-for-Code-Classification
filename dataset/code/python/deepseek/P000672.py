Sure, here is the Python code for the given problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def removeNthNode(head, n):
    dummy = ListNode(0)
    dummy.next = head
    first = second = dummy
    for i in range(n + 1):
        first = first.next
    while first:
        first = first.next
        second = second.next
    second.next = second.next.next
    return dummy.next

def createLinkedList(nums):
    dummy = cur = ListNode(0)
    for num in nums:
        cur.next = ListNode(num)
        cur = cur.next
    return dummy.next

def printLinkedList(head):
    while head:
        print(head.val, end=' ')
        head = head.next
    print()

def main():
    nums = [1,2,3,4,5,6,7,8,9,10]
    n = 3
    head = createLinkedList(nums)
    new_head = removeNthNode(head, n)
    printLinkedList(new_head)

if __name__ == "__main__":
    main()

In this code, we first define a ListNode class for a node in the linked list. Then, we define three functions: `removeNthNode`, `createLinkedList`, and `printLinkedList`. The `removeNthNode` function takes in the head of the linked list and the integer N, and returns the head of the modified linked list. The `createLinkedList` function takes in a list of numbers and creates a linked list from the list. The `printLinkedList` function takes in the head of a linked list and prints out the values of the nodes in the linked list.

In the `main` function, we first create a linked list with a list of numbers. We then call the `removeNthNode` function and print the result.