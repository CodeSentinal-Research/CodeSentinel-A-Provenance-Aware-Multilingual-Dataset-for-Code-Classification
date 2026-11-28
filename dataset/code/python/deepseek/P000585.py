Here is the Python code:


def reorderList(head):
    if not head:
        return 

    second_half_start = middle = head
    while fast and fast.next and fast.next.next:
        second_half_start = second_half_start.next
        middle = middle.next
        fast = fast.next.next

    prev, current = None, second_half_start.next
    while current:
        current.next, prev = prev, current
        current = current.next

    second_half_start.next = prev

    first_half, second_half = head, prev
    while first_half and second_half:
        first_next, second_next = first_half.next, second_half.next
        first_half.next = second_half
        second_half.next = first_next
        first_half, second_half = first_next, second_next


The main function would look like this:

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)

    reorderList(head)

    while head:
        print(head.val)
        head = head.next

if __name__ == "__main__":
    main()

This code works by first finding the middle of the linked list and then reversing the second half of the list. After that, it merges the two reversed lists together.