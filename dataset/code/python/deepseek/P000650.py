Here is the Python code:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def findNthFromBeginning(head, n):
    current = head
    for _ in range(n):
        if current is None:
            return -1
        current = current.next
    return current.val if current else -1

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    print(findNthFromBeginning(head, 2))  
    print(findNthFromBeginning(head, 5))  
    print(findNthFromBeginning(head, 10))  

if __name__ == "__main__":
    main()

In the code above, we first define a singly-linked list node with a constructor that takes an integer value x. Then, we define a function `findNthFromBeginning()` that takes in the head of the list and the index n (1-indexed), and returns the nth node's value. If the node does not exist, it returns -1.

In the main function, we create a linked list and print the values of the 2nd and 5th nodes, and the 10th node. The output of the main function is the expected values for the given inputs.