Sure, here's a Python solution for the problem using recursion and storing previously generated trees:

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def generateTrees(self, n: int):
    key_to_node = {0: None}

    def helper(lower = 1, upper = n):
        if lower == upper:
            return None
        for key in range(lower, upper + 1):
            for left in helper(lower, key - 1):
                for right in helper(key + 1, upper):
                    root = TreeNode(key)
                    root.left = left
                    root.right = right
                    key_to_node[key] = root
        return iter(key_to_node[k] for k in range(lower, upper + 1))

    return helper()

def main():
    N = 3
    trees = generateTrees(N)
    for i in range(1, N + 1):
        print(f"Tree for key {i}:")
        print_tree(trees[i-1])
        print()

def print_tree(node):
    if node is None:
        return
    print(f"Tree with root {node.val} is:")
    print(f"Node {node.val}")
    print(f"Left subtree: ", end="")
    print_tree(node.left)
    print(f"Right subtree: ", end="")
    print_tree(node.right)

if __name__ == "__main__":
    main()

In this code, we use a dictionary `key_to_node` to store previously generated trees for each key. For each key, we generate all possible trees by considering the key as the root of every subtree. We use a helper function `helper` to do this recursively. The base case of the recursion is when the range of keys is 1.

The main function tests the function for a range of keys from 1 to N, and prints out the trees for each key. The `print_tree` function is used to print out the trees.