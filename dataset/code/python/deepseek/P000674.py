Here's the Python code for the problem. 

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def rearrange(head):
    if not head or not head.next:
        return head

    odd = head
    even = head.next
    even_head = even

    new_head = even

    while odd and even:
        odd.next = even.next
        odd = odd.next
        even.next = odd.next if odd else None
        even = even.next

    return new_head

def create_list(nums):
    if not nums:
        return None

    head = ListNode(nums[0])
    cur = head
    for num in nums[1:]:
        cur.next = ListNode(num)
        cur = cur.next

    return head

def print_list(head):
    if not head:
        return

    while head:
        print(head.val, end=' ')
        head = head.next

    print()

if __name__ == '__main__':
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))
    head = create_list(nums)
    new_head = rearrange(head)
    print_list(new_head)

In the above code, we first create a helper class `ListNode` to represent a node in the linked list. Then we define a function `rearrange` to rearrange the linked list into zigzag pattern. This function creates a new head for the linked list that follows the pattern, and then sets `new_next` for each node to follow the zigzag pattern.

We also define a function `create_list` to create a linked list from a list of integers. We take in a list of integers, create a linked list from them, and return the head of the linked list.

Finally, we define a function `print_list` to print the values of a linked list. We print the values of the linked list followed by a newline.

The main function takes in the number of nodes, a list of integers representing the node values, creates a linked list from the integers, rearranges the linked list into zigzag pattern, and prints the values of the rearranged linked list.