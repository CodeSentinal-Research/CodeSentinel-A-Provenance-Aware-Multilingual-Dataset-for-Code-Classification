class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def solve(root):
    queue = [root]
    while queue:
        level = []
        for node in queue:
            level.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        print(sum(level) / len(level))
        queue = [n for node in queue if node]  

def main():
    N = int(input().strip())
    nodes = [TreeNode(int(x)) for x in input().strip().split()]
    for i in range(N-1):
        parent = nodes[i//2]
        if i % 2 == 0:
            parent.right = nodes[i//2 + 1]
        else:
            parent.left = nodes[i//2 + 1]
    root = nodes[0]
    solve(root)

main()
This Python code defines a `TreeNode` class for a node in a binary tree, and a `solve` function that computes and prints the average of the node values at every level. The `main` function reads the input, builds the binary tree, and calls `solve` to print the average values at every level.