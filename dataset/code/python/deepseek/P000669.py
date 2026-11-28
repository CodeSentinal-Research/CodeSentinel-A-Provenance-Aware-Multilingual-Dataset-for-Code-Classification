class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def findMin(head):
    if not head:
        return -1
    min_val = head.val
    current = head
    while current:
        if current.val < min_val:
            min_val = current.val
        current = current.next
    return min_val

def main():
    head = ListNode(4)
    head.next = ListNode(2)
    head.next.next = ListNode(1)
    head.next.next.next = ListNode(3)
    print(findMin(head))

    print(findMin(None))

    head = ListNode(1)
    print(findMin(head))

if __name__ == "__main__":
    main()