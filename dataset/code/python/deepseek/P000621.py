Here is the Python code to solve the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def removeNodes(head, threshold):
    if head is None:
        return None
    head.next = removeNodes(head.next, threshold)
    if head.val <= threshold:
        return head
    return head

def createLinkedList(arr):
    if len(arr) == 0:
        return None
    head = ListNode(arr[0])
    current = head
    for data in arr[1:]:
        current.next = ListNode(data)
        current = current.next
    return head

def printLinkedList(head):
    while head:
        print(head.val, end=' ')
        head = head.next
    print()

def main():
    arr = [1, 2, 6, 2, 3, 2, 2, 4, 2, 5]
    ll = createLinkedList(arr)
    threshold = 2
    ll = removeNodes(ll, threshold)
    printLinkedList(ll)

if __name__ == "__main__":
    main()

This code first defines a `ListNode` class for the nodes of the linked list. Then, it defines the `removeNodes` function, which is a recursive function that removes nodes from the linked list whose value is greater than the threshold. It first checks if the head of the linked list is None, and if it is, it returns None. Otherwise, it calls itself with the head's next node and the threshold, then it checks if the head's value is less than or equal to the threshold. If it is not, it returns the head. Otherwise, it returns the head.

In the `createLinkedList` function, it first checks if the array is empty, and if it is, it returns None. Otherwise, it creates a new ListNode with the first element of the array, and then it iterates through the remaining elements, creating a new ListNode for each one and linking them together in a singly linked list.

In the `main` function, it creates a linked list with an array of integers, sets a threshold, and calls the `removeNodes` function with the linked list and the threshold as arguments. It then prints the result.