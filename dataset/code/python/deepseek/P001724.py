Here is a Python solution using depth-first search (DFS) for the problem. The idea is to traverse the tree from the root to the leaf, updating the minimum sum as we go along.

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def solve(root):
    min_sum = float('inf')
    dfs(root, 0, min_sum)
    return min_sum

def dfs(node, curr_sum, min_sum):
    if not node:
        return
    curr_sum += node.val
    if not node.left and not node.right:
        min_sum = min(min_sum, curr_sum)
    else:
        dfs(node.left, curr_sum, min_sum)
        dfs(node.right, curr_sum, min_sum)

For input handling, you can use the following code.

def main():
    N = int(input().strip())
    nodes = [int(input().strip()) for _ in range(N)]
    nodes.append(-1)  
    tree = []
    for i in range(N):
        parent = nodes[i]
        if parent == -1 and i > 0:  
            tree.append(TreeNode(parent))
        else:
            if parent < i:  
                tree.append(TreeNode(parent))
                tree[i // 2].left = tree[-1]
            else:  
                tree.append(TreeNode(parent))
                tree[i // 2].right = tree[-1]
    min_sum = solve(tree[0])
    print(min_sum)

if __name__ == '__main__':
    main()

In this code, we use a list to represent the tree, where each element at index `i` is the parent of the `i-th` node in the tree. The list is built such that the root of the tree is at index 0, and each parent of a node is at index `i // 2`.