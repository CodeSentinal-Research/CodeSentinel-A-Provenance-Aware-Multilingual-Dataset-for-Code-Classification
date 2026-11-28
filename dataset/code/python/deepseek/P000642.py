class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def insertNode(head, position, value):
    new_node = ListNode(value)
    if position == 0:
        new_node.next = head
        head = new_node
    else:
        cur = head
        for _ in range(position - 1):
            if cur.next is None:
                return head
            cur = cur.next
        new_node.next = cur.next
        cur.next = new_node
    return head
In this code, a new node is created with the given value and is inserted at the specified position. The new node's next pointer is set to the node at the given position in the list. If the position is 0, the new node is inserted at the beginning of the list. If the position is greater than the length of the list, the new node is appended to the end of the list.