Here is the Python code with the main function and input handling:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def deleteDuplicates(head):
    if head is None:
        return None

    current = head
    data = {current.val}

    while current.next:
        if current.next.val in data:
            current.next = current.next.next
        else:
            data.add(current.next.val)
            current = current.next

    return head

To use this code, you would need to create a linked list with the nodes and pass it to the `deleteDuplicates` function. Here is an example of how to use it:

def main():
    head = ListNode(1)
    second = ListNode(2)
    third = ListNode(3)
    fourth = ListNode(2)
    fifth = ListNode(5)

    head.next = second
    second.next = third
    third.next = fourth
    fourth.next = fifth

    new_head = deleteDuplicates(head)

    while new_head:
        print(new_head.val)
        new_head = new_head.next

if __name__ == "__main__":
    main()

This will print:

1
2
3
5

This code uses a dictionary to keep track of the values that have been seen so far. It iterates over the list, and if it finds a value that it has seen before, it skips the next node. If it hasn't seen the value before, it adds it to the dictionary and moves to the next node.