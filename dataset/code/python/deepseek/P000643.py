def deleteFirstOccurrence(head, value):
    if head is None:
        return head

    if head.value == value:
        head = head.next
        return deleteFirstOccurrence(head, value)

    head.next = deleteFirstOccurrence(head.next, value)
    return head


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def createList(arr):
    dummy = ListNode(0)
    cur = dummy
    for i in arr:
        cur.next = ListNode(i)
        cur = cur.next
    return dummy.next


def printList(head):
    while head:
        print(head.val, end=' ')
        head = head.next
    print()


def main():
    head = createList([1, 2, 3, 4, 5])
    printList(head)
    head = deleteFirstOccurrence(head, 3)
    printList(head)


if __name__ == "__main__":
    main()