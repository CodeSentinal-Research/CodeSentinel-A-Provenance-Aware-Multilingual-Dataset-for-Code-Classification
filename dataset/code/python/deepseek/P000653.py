Here is the Python code for the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def pairSwap(head):
    if not head or not head.next:
        return head

    next_node = head.next
    head.next = pairSwap(next_node.next)
    next_node.next = head

    return next_node

def main():
    input = [1, 2, 3, 4]
    dummy_head = ListNode(0)
    current_node = dummy_head
    for num in input:
        current_node.next = ListNode(num)
        current_node = current_node.next
    new_head = pairSwap(dummy_head.next)
    while new_head:
        print(new_head.val)
        new_head = new_head.next

if __name__ == "__main__":
    main()

This program creates a linked list from a list of integers, then calls the `pairSwap` function to swap every pair of adjacent nodes in the list. It then prints out the values of the nodes in the modified list. 

This code assumes that you are using Python 3.x and the input list is sorted in ascending order. If not, you will need to implement some additional logic to handle the input in a specific way.