Here is the Python code for the problem. The code uses a recursive approach to solve the problem. The main idea is to calculate the longest Zigzag path for each node and then select the maximum one.

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def longestZigZag(root):
    def helper(node):
        if not node:
            return 0
        left = helper(node.left)
        right = helper(node.right)
        return max(left, right, 1 + left, 1 + right)

    return max(helper(root))

def main():
    root = Node(1)
    root.left = Node(1)
    root.right = Node(1)
    root.left.left = Node(1)
    root.left.right = Node(1)
    root.right.left = Node(1)
    root.right.right = Node(1)
    print(longestZigZag(root))

if __name__ == "__main__":
    main()

This code first defines a Node class to create a new node. Then it defines the longestZigZag function, which is a recursive function to calculate the longest Zigzag path. The helper function is a helper function to calculate the longest Zigzag path for a given node.

In the main function, it creates a test binary tree and prints the longest Zigzag path.

Please note that this code only works for the provided input. If you want to use this code with your own input, you would need to create a binary tree from a list of nodes.