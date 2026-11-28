Here is the Python code for the problem:

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.ans = 0

    def maxDepth(self, root):
        if not root:
            return 0
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

    def maxBST(self, root):
        if not root:
            return 0
        if not root.left and not root.right:
            return 1
        left = self.maxBST(root.left)
        right = self.maxBST(root.right)
        if left and right and self.isBST(root.left, root.left.val, root.right.val):
            return left + right + 1
        return max(left, right)

    def isBST(self, root, lower, upper):
        if not root:
            return True
        if not lower < root.val < upper:
            return False
        return self.isBST(root.left, lower, root.val) and self.isBST(root.right, root.val, upper)

    def solve(self, N, nodes):
        nodes = [int(node) for node in nodes]
        self.nodes = nodes
        self.N = N
        root = self.buildTree(nodes, 0, N-1)
        self.ans = self.maxDepth(root)
        self.diameter = self.maxBST(root)

    def buildTree(self, nodes, start, end):
        if start > end:
            return None
        mid = (start + end) // 2
        node = Node(nodes[mid])
        node.left = self.buildTree(nodes, start, mid-1)
        node.right = self.buildTree(nodes, mid+1, end)
        return node

    def main(self):
        N = int(input().strip())
        nodes = input().strip().split(' ')
        self.solve(N, nodes)
        print(self.ans)
        print(self.diameter)

if __name__ == '__main__':
    s = Solution()
    s.main()
This code first reads the number of nodes and the values of the nodes from the input. Then it builds the binary tree and calculates the diameter and the maximum depth of the largest Binary Search Tree subtree. The maximum depth is calculated using the depth-first search (DFS) algorithm. The maximum BST is calculated using the depth-first search (DFS) algorithm and a helper function isBST to check if a node is a valid Binary Search Tree.