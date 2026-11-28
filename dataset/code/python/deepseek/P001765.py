Here is the Python code:

def check_same_length(root):
    length = [0]

    def dfs(node, length):
        if not node:
            return False
        length += 1
        if node.left and node.right:
            return (dfs(node.left, length) and
                    dfs(node.right, length))
        elif node.left:
            return (dfs(node.left, length) and
                    abs(length - 1) < abs(length - 2))
        elif node.right:
            return (dfs(node.right, length) and
                    abs(length - 1) < abs(length - 2))
        return abs(length - 1) == abs(length - 2)

    return 'YES' if dfs(root, length) else 'NO'

def main():
    n = int(input())
    for _ in range(n):
        root = build_tree(input())
        print(check_same_length(root))

if __name__ == "__main__":
    main()

This code first defines a helper function `dfs` that performs depth-first search on the tree. It traverses the tree and for each node, it checks if the left and right children exist, and if they do, recursively call the `dfs` on them. If there are both left and right children, it checks if the length of the path is the same for both.

The main function reads the number of trees from the input, and for each tree, it reads the tree from input and calls the `check_same_length` function.

Please note that the `build_tree` function is not defined in this code, and it is assumed to be defined elsewhere. The `build_tree` function is supposed to read a line of input representing a tree in a special format, and return the root of the tree.

This code has a time complexity of O(n), where n is the number of nodes in the tree. This is because we are performing a depth-first search of the tree, and for each node, we are performing a constant amount of work (checking the length and possibly recursively calling dfs).