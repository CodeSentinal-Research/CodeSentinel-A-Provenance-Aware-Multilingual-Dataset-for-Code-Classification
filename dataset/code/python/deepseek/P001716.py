Here is a Python code snippet that uses a depth-first search (DFS) approach to find the lowest leaf node in a binary tree. 

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def find_min_depth_node(root):
    min_depth_node = root
    min_depth = float('inf')

    def dfs(node, depth):
        nonlocal min_depth_node, min_depth
        if node is not None:
            if depth < min_depth:
                min_depth = depth
                min_depth_node = node
            dfs(node.left, depth + 1)
            dfs(node.right, depth + 1)

    dfs(root, 0)

    return min_depth_node.value

def main():
    N = int(input())
    nodes = [input().split() for _ in range(N)]

    root = Node(int(nodes[0][0]))
    stack = [root]
    for node in nodes[1:]:
        parent_node = stack.pop()
        if node[0] == 'L':
            parent_node.left = Node(int(node[1]))
            stack.append(parent_node.left)
        else:
            parent_node.right = Node(int(node[1]))
            stack.append(parent_node.right)

    print(find_min_depth_node(root))

if __name__ == "__main__":
    main()

This code works by creating a binary tree from the input data and then using a depth-first search to find the lowest leaf node at the maximum depth. The depth-first search is performed using a recursive function `dfs`, which traverses the tree in a depth-first manner. When a node is visited, the function checks if the depth is less than the current minimum depth. If so, the node is set as the minimum depth node and the depth is updated. The process is repeated for the left and right children of the current node, and the function continues until the entire tree has been traversed.