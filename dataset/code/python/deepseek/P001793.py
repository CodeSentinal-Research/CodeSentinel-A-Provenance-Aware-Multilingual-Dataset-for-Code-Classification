Here's the Python code for the problem:

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def findInorderPredecessor(root, key):
    node = root
    while node:
        if node.val > key:
            predecessor = node
            node = node.left
        else:
            node = node.right
    return predecessor.val if predecessor else None

N = int(input().strip())
nodes = [TreeNode(int(line)) for line in [input().strip() for _ in range(N)]]
for i in range(1, N):
    if nodes[i-1].left and nodes[i-1].left.val > nodes[i].val:
        nodes[i-1].left = nodes[i]
    else:
        nodes[i-1].right = nodes[i]

key = int(input().strip())
print(findInorderPredecessor(nodes[0], key))

This code first reads the input for the number of nodes, and then for each node. It then reads the input for the target key. Finally, it prints the inorder predecessor of the target key.