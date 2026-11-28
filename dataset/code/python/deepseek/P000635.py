class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def reverseNodesInGroups(head, g, groups):
    def reverse(node, g):
        prev, curr, nxt = node, node.next, node.next
        count = 1
        while count < g and nxt is not None:
            nxt = nxt.next
            count += 1
        if count == g:
            prev.next = reverse(curr, g)
            curr.next = nxt
            return prev, curr
        return prev, None

    dummy = ListNode(0)
    dummy.next = head
    prev, head = dummy, reverse(head, g)[0]

    while prev.next is not None:
        prev = prev.next

    return head

def create_linked_list(arr):
    dummy = ListNode(0)
    prev, curr = dummy, None
    for num in arr:
        curr = ListNode(num)
        curr.next = prev
        prev = curr
    return dummy.next

def print_linked_list(head):
    while head:
        print(head.val, end=' ')
        head = head.next
    print()

def main():
    groups = [3, 2, 2, 1, 1]
    linked_list = create_linked_list([1, 2, 3, 4, 5, 6, 7, 8, 9])
    print_linked_list(linked_list)
    linked_list = reverseNodesInGroups(linked_list, 1, groups)
    print_linked_list(linked_list)

main()