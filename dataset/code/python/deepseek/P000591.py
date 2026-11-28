def listNode(val = 0, next = None):
    return [val, next]

class LinkedList:
    def __init__(self, nodes = None):
        self.head = None
        if nodes is not None:
            node = listNode(data = nodes.pop(0))
            self.head = node
            for elem in nodes:
                node.next = listNode(data = elem)
                node = node.next

def intersection(headA, headB):
    if headA is None or headB is None:
        return None
    curA = headA
    while curA.next is not None:
        curA = curA.next
    curA.next = headB
    slow = fast = headA
    while fast is not None and slow is not None:
        fast = fast.next
        slow = slow.next
        if fast is None:
            break
    if slow is None:
        return None
    return slow.val

list1 = LinkedList(nodes = [1, 2, 3, 4, 5])
list2 = LinkedList(nodes = [6, 7, 8, 9])

print(intersection(list1.head, list2.head))