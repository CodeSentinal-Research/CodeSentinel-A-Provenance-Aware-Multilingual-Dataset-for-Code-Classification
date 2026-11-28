class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def deleteNodes(head):
    if not head:
        return None

    current = head
    max_val = head.val
    head.val = 0

    while current:
        if current.val >= max_val:
            max_val = current.val
        current = current.next

    current = head
    while current:
        if current.val >= max_val:
            temp = current.next
            current.next = temp.next
            temp.next = None
        else:
            max_val = current.val
        current = current.next

    return head

def create_linked_list(arr):
    if not arr:
        return None

    head = ListNode(arr[0])
    current = head
    for i in arr[1:]:
        current.next = ListNode(i)
        current = current.next

    return head

def print_linked_list(head):
    if not head:
        print("Linked list is empty")
        return

    current = head
    while current:
        print(current.val, end=" ")
        current = current.next
    print()

def main():
    arr = [1, 2, 3, 4, 5]
    head = create_linked_list(arr)
    print_linked_list(head)
    head = deleteNodes(head)
    print_linked_list(head)

if __name__ == "__main__":
    main()