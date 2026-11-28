Here is the Python code for the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def findMax(head):
    if head is None:
        return -1
    max_value = head.val
    current = head.next

    while current:
        if current.val > max_value:
            max_value = current.val
        current = current.next

    return max_value

def main():
    head = None
    result = findMax(head)
    print(result)  

    head = ListNode(1)
    result = findMax(head)
    print(result)  

    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    result = findMax(head)
    print(result)  

if __name__ == "__main__":
    main()

In this code, we are defining a LinkedList class with a node class inside it. The ListNode class is used to initialize the value of the node and the next pointer.

The findMax function is used to find the maximum value in the linked list. If the list is empty, it returns -1. Otherwise, it initializes the max_value variable to the value of the first node and then traverses the list, updating max_value if a node's value is greater. After traversing the list, it returns the max_value.

The main function tests the findMax function with an empty list, a list with one node, and a list with multiple nodes.