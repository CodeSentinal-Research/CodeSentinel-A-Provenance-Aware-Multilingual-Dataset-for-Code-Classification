Sure, here is a Python solution using recursive approach to generate all the unique Binary Search Trees (BSTs).

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def generateTrees(n):
    def generate(start, end):
        if start > end:
            return [None,]

        all_trees = []
        for i in range(start, end + 1):
            for left in generate(start, i - 1):
                for right in generate(i + 1, end):
                    root = TreeNode(i + 1)
                    root.left = left
                    root.right = right
                    all_trees.append(root)

        return all_trees

    return generate(1, n) if n else []

def main():
    n = int(input("Enter the number of nodes: "))
    result = generateTrees(n)
    print("All unique Binary Search Trees with", n, "nodes:")
    for i in range(len(result)):
        print("Tree", i + 1, ":")
        print_tree(result[i])

def print_tree(tree, depth=0):
    if tree is not None:
        print_tree(tree.right, depth + 1)
        print('    ' * depth + '->', tree.val)
        print_tree(tree.left, depth + 1)
    else:
        print('    ' * depth)

if __name__ == "__main__":
    main()

In this program, we define a TreeNode class for each node in the BST. The generateTrees function recursively generates all the BSTs by checking all possible combinations of the root node and its children. 

The main function first takes an input for the number of nodes. Then it calls the generateTrees function and prints all the BSTs with the given number of nodes.

The print_tree function is used to print the binary tree.

Please note that this program is not the optimal way to generate all unique BSTs. It is based on the idea of generating all the BSTs and keeping them in a list, and then returning that list in the end. This approach can be improved by using a more efficient algorithm.