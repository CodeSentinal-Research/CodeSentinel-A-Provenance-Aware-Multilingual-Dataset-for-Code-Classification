Here is the Python code for the problem:

def find_longest_alternating_path(root):
    def helper(node):
        if not node:
            return 0
        left = helper(node.left)
        right = helper(node.right)
        return max(
            left + ((node.val % 2 == 0) == (node.left and node.left.val % 2 == 0)),
            right + ((node.val % 2 == 1) == (node.right and node.right.val % 2 == 1))
        )
    return max(0, helper(root))

This function uses recursive approach to solve the problem. For each node, it calculates the maximum length for the alternate path ending at that node. It is calculated by comparing the node value with the value of the left child or right child. If they're both even or both are odd, it means we can extend the path from the current node to the left child and the right child. If only one child is even and the other is odd, it means we can only extend the path from the current node to the other child.

Here is the main function:

if __name__ == "__main__":
    n = int(input().strip())
    nodes = list(map(int, [input() for _ in range(n)]))
    tree = [None] * n
    for i in range(n):
        if nodes[i] == -1:
            tree[i] = None
        else:
            left, right = nodes[i] * 2, nodes[i] * 2 + 1
            tree[i] = [tree[left], tree[right]]
    print(find_longest_alternating_path(tree[0]))

This main function reads the number of nodes, then the values of the nodes. It then constructs a tree from the values. Finally, it calls the `find_longest_alternating_path` function to find the longest alternating path.