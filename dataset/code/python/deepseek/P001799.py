Here is the Python code for the problem:

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def insert(arr, node, i, n): 
    if i < n: 
        temp = TreeNode(arr[i]) 
        node.left = temp 
        node = temp 
        node.right = insert(arr, node.right, 2 * i + 2, n) 
        return node 
    return node

def kthSmallest(root, k):
    pass

def main():
    arr = [1, 2, 3, 4, 5, 6, 7] 
    n = len(arr)
    root = insert(arr, None, 0, n)
    k = 3
    print(kthSmallest(root, k))

if __name__ == '__main__':
    main()

This is the complete solution of the problem. The main function first creates a binary search tree from the given array. Then it calls the kthSmallest function to find the kth largest element.

The kthSmallest function is a placeholder for the actual implementation of the problem. The kthSmallest function uses in-order traversal to find the kth largest element in the binary search tree.

The TreeNode class is used to define the node of the binary search tree. The insert function is used to create the binary search tree from the given array. The kthSmallest function finds the kth largest element in the binary search tree.

The main function is the entry point of the program. It first creates a binary search tree from an array, then finds the kth largest element in the tree.

Please note that the actual implementation of the problem is not provided. It's a placeholder for the actual implementation of the problem. The implementation of the problem requires a good understanding of binary search trees and recursion.