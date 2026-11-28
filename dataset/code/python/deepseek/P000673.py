def move_last_node_to_front(head):
    if not head:
        return None

    prev = None
    curr = head
    while curr.next:
        prev = curr
        curr = curr.next

    prev.next = None

    curr.next = head
    head = curr

    return head


def main():
    class ListNode:
        def __init__(self, x):
            self.val = x
            self.next = None

    def string_to_listnode(l):
        if not l: return None
        head = ListNode(l[0])
        curr = head
        for i in l[1:]:
            curr.next = ListNode(i)
            curr = curr.next
        return head

    line = [1, 2, 3, 4, 5]
    l = string_to_listnode(line)
    res = move_last_node_to_front(l)

    while res:
        print(res.val)
        res = res.next


if __name__ == '__main__':
    main()