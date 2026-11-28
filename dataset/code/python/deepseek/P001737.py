Here is a Python solution that uses Depth-First Search (DFS) to find the largest perfect subtree. The logic is to recursively calculate the size of each subtree and the depth of each node. In the end, we return the maximum depth and size of the largest perfect subtree.

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def dfs(node):
    if not node:
        return 0, 0
    left_size, left_depth = dfs(node.left)
    right_size, right_depth = dfs(node.right)
    if left_depth > right_depth:
        temp = left_size + right_size + 1
    elif left_depth < right_depth:
        temp = left_size + right_size + 1
    else:
        temp = left_size + right_size + 1
    if temp > size:
        size = temp
        depth = max(left_depth, right_depth) + 1
    return temp, depth

def main():
    global size
    size = 0
    n = int(input())
    nodes = [None] + [Node(int(x)) for x in input().split()]
    for i in range(1, n + 1):
        nodes[i].left = nodes[int(input().split()[0])]
        if int(input().split()[0]) != -1:
            nodes[i].right = nodes[int(input().split()[0])]
    dfs(nodes[1])
    print(size)

if __name__ == "__main__":
    main()

This program uses the Node class to create the binary tree. Each Node object has a value, and left and right pointers to the left and right children, respectively. The main function reads the number of nodes, creates the tree, and calls the dfs function. The dfs function returns the size of the largest perfect subtree and its depth. The maximum size and depth are updated if a larger perfect subtree is found.

Please note that this code assumes that the input for the binary tree is correctly formed, and the nodes are connected in a binary tree.