class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

def insert(head, insertVal):
    if head is None:
        new_node = Node(insertVal)
        new_node.next = new_node
        return new_node
    
    curr, next_node = head, head.next

    while True:
        if curr.value <= insertVal <= next_node.value:
            break
        elif curr.value > next_node.value:
            if curr.value <= insertVal or next_node.value >= insertVal:
                break
        curr = curr.next
        next_node = next_node.next
        if curr == head:
            break

    curr.next = Node(insertVal, next_node)
    next_node.next = curr.next

    return head