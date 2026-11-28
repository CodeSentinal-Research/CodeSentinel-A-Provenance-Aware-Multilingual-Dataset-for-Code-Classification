Here is a Python solution for the problem. This solution uses a recursive approach to construct the Binary Search Tree (BST). It first converts the input array into a list of tuples, where each tuple contains the value and its index in the sorted array. It then sorts this list in ascending order based on the second element of each tuple, which is the value itself. After sorting, it uses the sorted list to construct the BST.

class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def sortedArrayToBST(arr):
    if not arr:
        return None

    mid = len(arr) // 2

    root = Node(arr[mid][1])

    root.left = sortedArrayToBST(arr[:mid])
    root.right = sortedArrayToBST(arr[mid+1:])

    return root

def preOrder(node):
    if not node:
        return
    print(node.val, end=' ')
    preOrder(node.left)
    preOrder(node.right)

def main():
    t = int(input().strip())

    for i in range(t):
        n = int(input().strip())
        arr = [(int(x), idx) for idx, x in enumerate(input().strip().split())]
        arr.sort()  
        sorted_bst = sortedArrayToBST(arr)
        preOrder(sorted_bst)
        print()

if __name__ == '__main__':
    main()

This code will accept multiple test cases and then for each test case, it will print the pre-order traversal of the constructed BST.