Here is the Python code for the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def reverseLinkedList(head):
    prev = None
    current = head
    while current is not None:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    return prev

def main():
    nums = list(map(int, input().split()))
    head = ListNode(nums[0])
    current = head
    for num in nums[1:]:
        current.next = ListNode(num)
        current = current.next
    head = reverseLinkedList(head)
    while head is not None:
        print(head.val)
        head = head.next

if __name__ == "__main__":
    main()

This code defines a class `ListNode` to represent a node in the linked list. It takes an integer `x` as an argument and initializes a node with value `x`. The `next` attribute of a node is a reference to the next node in the list.

In the `reverseLinkedList` function, a node is initialized with `None` as the previous node and the head as the current node. Then, in a loop, the previous node and the current node are swapped. If there are more nodes, the function keeps looping until there are no more nodes. At the end of the loop, the previous node is the new head of the reversed list.

The `main` function is the entry point of the program. It reads a list of numbers from the input, creates a linked list from the numbers, reverses the linked list, and prints the reversed list.

Please note that this code assumes the input list is formatted as integers separated by spaces, and there are no spaces before the first number. If the input list is not formatted as integers separated by spaces, you may need to adjust the input handling part.