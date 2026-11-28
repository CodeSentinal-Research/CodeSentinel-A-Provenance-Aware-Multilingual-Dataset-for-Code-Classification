Here is the Python code for the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def reverseAlternateKNodes(head, k):
    if not head or k <= 0:
        return head

    curr = head
    while curr and curr.next:
        end = curr.next
        for _ in range(1, k - 1):
            end = end.next
        if end.next:
            next_node = end.next
            end.next = None
            prev, curr = None, head if curr == end else curr
            while prev is not None:
                next_node, curr.next = curr.next, prev
                prev, curr = curr, next_node
            if end == curr:
                end.next = reverseAlternateKNodes(next_node, k)
            else:
                end.next = next_node
        curr = end.next

    return head

The main function to handle the input is as follows:

def main():
    n = int(input().strip())
    values = list(map(int, input().strip().split()))
    k = int(input().strip())

    head = ListNode(values[0])
    curr = head
    for val in values[1:]:
        curr.next = ListNode(val)
        curr = curr.next

    head = reverseAlternateKNodes(head, k)

    while head:
        print(head.val, end=' ')
        head = head.next

if __name__ == '__main__':
    main()

In this code, we first parse the input to create the linked list. Then we call the `reverseAlternateKNodes` function to reverse the linked list. Finally, we print the reversed linked list.