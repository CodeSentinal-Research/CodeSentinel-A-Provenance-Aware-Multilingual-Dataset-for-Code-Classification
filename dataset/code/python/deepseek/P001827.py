Here is the Python code for the problem:

def areIdentical(root1, root2):
    if root1 is None and root2 is None:
        return True
    if root1 is not None and root2 is not None:
        if root1.val == root2.val:
            return (areIdentical(root1.left, root2.left) and
                    areIdentical(root1.right, root2.right))
    return False

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def createTree(nodes, root, i, n):
    if i < n:
        temp = TreeNode(nodes[i])
        root = temp
        root.left = createTree(nodes, root.left, 2 * i + 1, n)
        root.right = createTree(nodes, root.right, 2 * i + 2, n)
    return root

def main():
    n = int(input())
    nodes = list(map(int, input().split()))
    root1 = createTree(nodes, None, 0, n)
    n = int(input())
    nodes = list(map(int, input().split()))
    root2 = createTree(nodes, None, 0, n)
    if(areIdentical(root1, root2)):
        print("YES")
    else:
        print("NO")

if __name__=='__main__':
    main()

This code first reads the number of nodes in both trees, and then the values of the nodes. These values are used to create the two binary search trees. It then checks if the two trees are identical by recursively comparing the roots of the two trees. If at any point the trees are not identical, the function returns False. If all the trees are identical, the function returns True.

The `TreeNode` class represents a node in the tree. Each node has a value and two children (left and right), which are the left and right children of the node.

The `createTree` function is a recursive function that creates a binary search tree from a list of nodes. It takes as arguments the root of the tree, the index of the current node, and the total number of nodes. It creates a new node for the current node, and recursively calls `createTree` to create the left and right children of the new node.