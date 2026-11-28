Here is a Python solution using a depth-first search approach. The main idea is to calculate the product of the sum of subtrees before and after removing the edge. We keep track of the maximum product and update it whenever we find a better solution.

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def maxProduct(root):
    sums = []
    total = postorder(root, sums)
    max_prod = 0
    for i in range(len(sums)):
        prod = sums[i] * total - sums[i]
        max_prod = max(max_prod, prod)
    return max_prod

def postorder(root, sums):
    if root is None:
        return 0
    left = postorder(root.left, sums)
    right = postorder(root.right, sums)
    sums.append(root.val + left + right)
    return root.val + left + right

import sys
n = int(sys.stdin.readline().strip())
values = list(map(int, sys.stdin.readline().strip().split()))[:n]
mod = 10**9 + 7
tree = []
for i in range(n):
    if values[i] != -1:
        tree.append(TreeNode(values[i]))
    if 2*i+1 < n:
        tree[i].left = tree[2*i+1]
    if 2*i+2 < n:
        tree[i].right = tree[2*i+2]

root = tree[0]
sys.stdout.write(str(maxProduct(root)) + '\n')

This code first reads the input, then builds the tree by adding nodes from the input list. The function `maxProduct(root)` returns the maximum product of the sum of the two resulting subtrees.

The postorder function is used to calculate the sum of all nodes in the tree. The postorder function uses a depth-first search approach to traverse the tree and calculate the sum of each node. The sums are stored in the list `sums`.

The main function reads the input, then calls `maxProduct(root)` to find the maximum product. The result is printed to the standard output.

Please note that the code assumes that the input is valid. The code does not handle the edge case where the input does not represent a valid binary tree. You may need to add error handling code for such cases.