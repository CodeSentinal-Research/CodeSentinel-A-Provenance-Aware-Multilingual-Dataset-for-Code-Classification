class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def merge_nodes(head):
    dummy = ListNode(0)
    dummy.next = head
    prev, curr = dummy, head

    while curr:
        if curr.val == 0:
            if curr.next and curr.next.val == 0:
                val = 0
                while curr and curr.val == 0:
                    val += curr.val
                    curr = curr.next
                curr = curr.next
                prev.val = val
                prev = prev.next
            else:
                prev = curr
        else:
            if curr.next and curr.next.val == 0:
                curr.val = 0
                while curr and curr.val == 0:
                    curr.val += curr.val
                    curr = curr.next
            curr = curr.next
    if prev.next:
        prev.next = None
    return dummy.next