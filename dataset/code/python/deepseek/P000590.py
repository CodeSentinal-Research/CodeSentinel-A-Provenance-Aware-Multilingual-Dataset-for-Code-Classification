Here is the Python code for the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def is_palindrome(head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    prev = slow.next
    slow.next = slow.next.next
    prev.next = None

    head_second_half = prev
    tail = slow.next
    while tail:
        if head.val != tail.val:
            return False
        head = head.next
        tail = tail.next

    return True

def create_list(lst):
    dummy = ListNode(0)
    ptr = dummy
    for item in lst:
        ptr.next = ListNode(item)
        ptr = ptr.next
    return dummy.next

def main():
    lst = [1, 2, 3, 2, 1]
    head = create_list(lst)
    print(is_palindrome(head))

if __name__ == '__main__':
    main()

In this code, we first find the middle point of the linked list. Then we reverse the second half of the list. Finally, we compare the first half and the reversed second half to see if they are the same.