Here is the Python code for the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def insertAtBeginning(head, value):
    newNode = ListNode(value)
    newNode.next = head
    return newNode

def printList(head):
    if head is None:
        print(" ")
    else:
        print(head.val, end=" ")
        while head.next is not None:
            head = head.next
            print(head.val, end=" ")
        print(" ")

def main():
    head = None
    for val in input().split():
        head = insertAtBeginning(head, int(val))
    printList(head)

if __name__ == "__main__":
    main()

This code first defines a ListNode class to represent a node in the linked list. The insertAtBeginning function creates a new node with the given value and sets its next pointer to the current head of the list. The printList function prints the values of the linked list from the head node to the tail. In the main function, the head node is initially None, and the values of the linked list are read from input. The values are inserted at the beginning of the list, and the updated list is printed.