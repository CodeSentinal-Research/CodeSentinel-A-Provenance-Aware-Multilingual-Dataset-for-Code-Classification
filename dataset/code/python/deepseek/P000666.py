Here is the Python code with input handling and the main function:

class Node:
    def __init__(self, x):
        self.val = x
        self.bottom = None

def mergeTwoLists(l1, l2):
    if not l1 or not l2:
        return l1 or l2

    if l1.val < l2.val:
        l1.bottom = mergeTwoLists(l1.bottom, l2)
        return l1
    else:
        l2.bottom = mergeTwoLists(l1, l2.bottom)
        return l2

def create_list(arr):
    if not arr:
        return None

    head = Node(arr[0])
    cur = head

    for data in arr[1:]:
        node = Node(data)
        cur.bottom = node
        cur = node

    return head

def print_list(head):
    while head:
        print(head.val, end=" -> " if head.bottom else ".\n")
        head = head.bottom

def main():
    arr1 = [1, 3, 5]
    arr2 = [2, 4, 6]

    l1 = create_list(arr1)
    l2 = create_list(arr2)

    print("First list: ")
    print_list(l1)

    print("Second list: ")
    print_list(l2)

    merged = mergeTwoLists(l1, l2)

    print("Merged list: ")
    print_list(merged)

main()

This code creates a linked list using an array and then merges the two lists using the mergeTwoLists function. The main function demonstrates how to use this function with two sorted linked lists and how to print the merged list.