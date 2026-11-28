Sure, here is the Python code that accomplishes the task.

def flipEquivalentTrees(root1, root2):
    def inorder(root):
        if root:
            inorder(root.left)
            nodes.append(root.val)
            inorder(root.right)

    nodes = []
    inorder(root1)
    inorder(root2)

    return nodes == [n for n in reversed(nodes)]

Here is how you can use this function:

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def build_tree(nodes, i):
    if i < len(nodes) and nodes[i] is not None:
        node = TreeNode(nodes[i])
        node.left = build_tree(nodes, 2 * i + 1)
        node.right = build_tree(nodes, 2 * i + 2)
        return node

def main():
    nodes1 = [1, 2, 3, 4, 5, None, None, None, None, None]
    nodes2 = [1, 3, 2, None, None, None, 5, None, None, None]

    root1 = build_tree(nodes1, 0)
    root2 = build_tree(nodes2, 0)

    print('Yes' if flipEquivalentTrees(root1, root2) else 'No')

main()

In this code, we first define a helper function `inorder` which traverses a tree in inorder and stores the node values in a list. Then, we call this function on both trees and check if the lists of node values are equal. If they are, the trees are flip equivalent; otherwise, they are not.