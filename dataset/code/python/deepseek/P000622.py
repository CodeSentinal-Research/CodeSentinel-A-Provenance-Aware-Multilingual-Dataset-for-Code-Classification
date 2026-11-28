def detectCycle(self, head):
    if not head:
        return (0, 0)

    slow, fast = head, head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            break

    if not fast or not fast.next:
        return (0, 0)

    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next

    return (1, self.getLen(fast))

def getLen(self, node):
    p1, p2 = node, node
    length = 0

    while True:
        p1 = p1.next
        length += 1
        if p1 == p2:
            break

    return length