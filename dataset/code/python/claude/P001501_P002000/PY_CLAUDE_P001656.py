
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def insertAtEnd(self, head: ListNode, val: int) -> ListNode:
        node = ListNode(val)
        if not head:
            return node
        curr = head
        while curr.next:
            curr = curr.next
        curr.next = node
        return head
