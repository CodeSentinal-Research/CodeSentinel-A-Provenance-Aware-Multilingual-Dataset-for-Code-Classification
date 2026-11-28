Here is the Python code:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def deleteEveryKthNode(head, k):
    if k == 1 and head is None:
        return None

    current = head
    count = 1

    while current is not None:
        if count % k == 0:
            if current == head:
                head = head.next
            else:
                prev.next = current.next
            count = 1
        else:
            prev = current
            count += 1
        current = current.next

    return head

def printList(head):
    current = head
    while current is not None:
        print(current.val, end=' ')
        current = current.next
    print()

def main():
    head = ListNode(1)
    current = head
    for i in range(2, 6):
        current.next = ListNode(i)
        current = current.next

    print("Original list:")
    printList(head)

    k = int(input("Enter k: "))
    head = deleteEveryKthNode(head, k)

    print("List after deleting every k-th node:")
    printList(head)

if __name__ == "__main__":
    main()

The `deleteEveryKthNode` function iterates through the linked list, skipping every `k` nodes. If `k` is 1, it just returns None. Otherwise, it deletes the node pointed to by the current pointer if the current count is divisible by `k`. The `printList` function prints the values of all nodes in the linked list. The `main` function creates a linked list, prompts the user for `k`, and prints the list after deletion.