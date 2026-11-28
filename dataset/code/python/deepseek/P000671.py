class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def isSorted(head):
    current = head
    while current and current.next:
        if current.val > current.next.val:
            return False
        current = current.next
    return True

def main():
    node_values = [4, 2, 3, 5]
    head = None
    current = None

    for val in node_values:
        if head is None:
            head = ListNode(val)
            current = head
        else:
            current.next = ListNode(val)
            current = current.next

    print(isSorted(head))

if __name__ == "__main__":
    main()
This python code provides a solution for the problem by creating a Linked List with the given list of node values and then checking if the Linked List is sorted or not. The `isSorted` function traverses the Linked List and checks if the current node's value is greater than the next node's value. If it is, the function returns False, indicating that the Linked List is not sorted. If no such pair of values is found, the function returns True, indicating that the Linked List is sorted.

The `main` function creates a Linked List with the given list of node values and then calls the `isSorted` function with the head of the Linked List as its argument. It then prints the result of the `isSorted` function.