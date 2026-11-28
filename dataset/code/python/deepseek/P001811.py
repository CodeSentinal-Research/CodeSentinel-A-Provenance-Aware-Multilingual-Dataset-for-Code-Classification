Here is the Python code for the problem. The code uses the concept of DFS (Depth-First Search) to solve the problem.

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def largest_bst_subtree(root):
    def largest_bst_util(root):
        if not root:
            return (0, float('inf'), float('-inf'), True)

        left = largest_bst_util(root.left)
        right = largest_bst_util(root.right)

        is_bst = left[3] and right[3] and root.val > left[1] and root.val < right[0]

        if is_bst:
            size = left[0] + right[0] + 1
            min_val = min(left[1], root.val)
            max_val = max(right[2], root.val)
            return (size, min_val, max_val, is_bst)

        return (max(left[0], right[0]), float('-inf'), float('inf'), is_bst)

    return largest_bst_util(root)[0]


def main():
    N = int(input().strip())
    nodes = [None] * (N + 1)
    for i in range(1, N + 1):
        row = input().strip().split()
        parent = int(row[0])
        if parent == -1:
            root = nodes[i]
        else:
            nodes[i].left = nodes[parent]
            nodes[i].right = None
    largest_bst_subtree(root)


if __name__ == "__main__":
    main()

This code first reads the number of nodes (N), then it reads the nodes and their parent relationships. The `main` function reads the input and calls the `largest_bst_subtree` function, which returns the size of the largest BST subtree.