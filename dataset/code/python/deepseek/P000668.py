Here is the Python code for the given problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def skipM_N(head, M, N):
    dummy = ListNode(0)
    dummy.next = head

    skip = dummy
    skipNext = dummy.next

    while skipNext != None:
        for i in range(1, M):
            if skipNext == None:
                return dummy.next
            skipNext = skipNext.next
        if skipNext != None:
            skipNext = skipNext.next
        if skipNext != None:
            for i in range(1, N):
                if skipNext == None:
                    return dummy.next
                skipNext = skipNext.next
        skip.next = skipNext
        skip = skip.next

    return dummy.next

And here is a main function:

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    result = skipM_N(head, 2, 2)

    while result != None:
        print(result.val)
        result = result.next

if __name__ == "__main__":
    main()

This code first creates a linked list with the given nodes and then calls the `skipM_N` function with the head of the list and the values of M and N. It then prints the values of the modified linked list.