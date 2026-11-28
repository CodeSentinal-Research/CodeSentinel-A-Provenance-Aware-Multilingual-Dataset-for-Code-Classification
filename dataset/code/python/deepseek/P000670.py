Here is the Python code for the problem:

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def sum_of_nodes(head):
    if head is None:
        return 0

    total = 0
    current = head

    while current is not None:
        total += current.val
        current = current.next

    return total

def create_linked_list(nums):
    if not nums:
        return None

    head = ListNode(nums[0])
    current = head

    for num in nums[1:]:
        current.next = ListNode(num)
        current = current.next

    return head

def main():
    nums = [1, 2, 3, 4, 5]
    head = create_linked_list(nums)
    print(sum_of_nodes(head))

if __name__ == "__main__":
    main()

This code creates a singly linked list by creating a `ListNode` class and using a `create_linked_list` function. The `create_linked_list` function takes a list of integers and uses the `ListNode` class to create linked list nodes with the given integers.

The `sum_of_nodes` function takes the head of the linked list and sums up all the values in the linked list by traversing the linked list node by node. It uses a while loop to iterate over each node in the linked list, adding the value of the current node to the `total` variable.

Finally, the `main` function is the entry point of the program. It creates a linked list with the integers [1, 2, 3, 4, 5], and then prints the sum of all nodes in the linked list.