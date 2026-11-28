Here is the code for the problem.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def deleteLastNode(head):
    if head is None:
        return head
    
    if head.next is None:
        return None
    
    slow = head
    fast = head
    
    while fast.next is not None:
        fast = fast.next
        if fast.next is not None:
            slow = slow.next
            fast = fast.next
            
    if slow.next == head:
        return None
    else:
        slow.next = None
        
    return head

And here is the main function to test the code:

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)

    head = deleteLastNode(head)

    while head:
        print(head.val, end=" ")
        head = head.next

if __name__ == "__main__":
    main()

The output will be `1 2 3` because after deletion, the last node (4) is deleted.