Here is the Python code:

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

def max_twin_sum(head):
    max_sum = 0

    current = head
    prev = None

    while current is not None:
        if prev is None:
            prev = current
            current = current.next
        else:
            twin_sum = prev.value + current.value
            max_sum = max(max_sum, twin_sum)
            prev = current
            current = current.next

    return max_sum

def create_linked_list(nums):
    head = None
    current = None
    for num in nums:
        new_node = Node(num)
        if head is None:
            head = new_node
            current = new_node
        else:
            current.next = new_node
            current = new_node
    return head

def main():
    nums = [1, 2, 3, 4, 5, 6]
    head = create_linked_list(nums)
    twin_sum = max_twin_sum(head)
    print(f"Max twin sum is: {twin_sum}")

if __name__ == "__main__":
    main()

In this code, we first create a linked list using the `create_linked_list` function. Then, we pass the head of the linked list to the `max_twin_sum` function to find the maximum twin sum. Finally, we print the result.

The `create_linked_list` function creates a linked list with the given numbers. It takes a list of numbers as input, creates a new node for each number, and links them together. It returns the head of the linked list.

The `max_twin_sum` function finds the maximum twin sum among all twin pairs. It iterates through the linked list, keeping track of the current node and its previous node. It calculates the twin sum of the current node and its previous node and updates the max sum if necessary. It continues until it has iterated through all nodes. It returns the max sum.