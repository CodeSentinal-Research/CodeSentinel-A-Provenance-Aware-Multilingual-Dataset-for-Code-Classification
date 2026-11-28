Here is the Python code for the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def deleteNode(node):
    node.val = node.next.val
    node.next = node.next.next

def printList(head):
    curr_node = head
    while curr_node:
        print(curr_node.val, end=" ")
        curr_node = curr_node.next
    print()

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)

    print("Before deletion: ")
    printList(head)

    deleteNode(head.next)

    print("After deletion: ")
    printList(head)

if __name__ == "__main__":
    main()

In this code, a linked list is created with the values 1, 2, 3, and 4. The `deleteNode` function is called with the node to be deleted as the argument. This function is then called within the `main` function to demonstrate the functionality of the problem.