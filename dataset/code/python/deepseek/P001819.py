Sure, here is the Python code for the problem. I'm assuming that the input is given as a list where the first element is the root node and the rest are the child nodes.

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def construct_bst(nodes):
    root = None
    stack = []
    for data in nodes:
        node = Node(data)
        if not root:
            root = node
        if stack:
            if stack[-1].left is None:
                stack[-1].left = node
            else:
                stack[-1].right = node
        stack.append(node)
    return root

def count_nodes(root, x):
    if root is None:
        return 0
    if root.data < x:
        return 1 + count_nodes(root.left, x) + count_nodes(root.right, x)
    elif root.data == x:
        return count_nodes(root.left, x) + count_nodes(root.right, x) + 1
    else:
        return count_nodes(root.left, x)

def rank_of_key(nodes, x):
    root = construct_bst(nodes)
    return count_nodes(root, x)

def main():
    nodes = list(map(int, input().split()))[1:]
    x = int(input())
    print(rank_of_key(nodes, x))

if __name__ == "__main__":
    main()

In this code, we first construct the binary search tree from the given list of nodes. Then, we count the number of keys strictly smaller than x in the tree.

The `construct_bst` function constructs the binary search tree from the given list of nodes. The `count_nodes` function counts the number of nodes in the binary search tree that are less than or equal to x. Finally, the `rank_of_key` function calls both of these functions to get the rank of x.

In the `main` function, we read the nodes and x from the input and call the `rank_of_key` function to get the rank of x.

Please note that the input is a list of integers where the first integer is the root of the binary search tree and the rest of the integers are the child nodes of the root.