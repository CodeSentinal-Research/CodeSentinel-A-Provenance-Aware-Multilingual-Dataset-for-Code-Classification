class Node:
    def __init__(self, x):
        self.val = x
        self.next = None

def split_circular_linked_list(head):
    if not head:
        return None, None

    slow, fast = head, head

    while fast.next != head and fast.next.next != head:
        slow = slow.next
        fast = fast.next.next

    n1 = head
    n2 = slow.next
    slow.next = None
    fast.next = None

    return n1, n2

def create_circular_linked_list(arr):
    if not arr:
        return None

    last = Node(arr[0])
    head = last
    for data in arr[1:]:
        node = Node(data)
        last.next = node
        last = node
    last.next = head
    return head

def main():
    arr = [1, 2, 3, 4, 5, 6]
    head = create_circular_linked_list(arr)
    n1, n2 = split_circular_linked_list(head)
    print('First list: ', n1)
    print('Second list: ', n2)

if __name__ == "__main__":
    main()