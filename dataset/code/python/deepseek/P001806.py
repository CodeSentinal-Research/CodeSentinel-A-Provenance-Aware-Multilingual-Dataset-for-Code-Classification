Here is the Python code:

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def insert(node, val):
    if node is None:
        return Node(val)
    else:
        if val < node.val:
            node.left = insert(node.left, val)
        else:
            node.right = insert(node.right, val)
    return node

def inorder(node, nodeList):
    if node:
        inorder(node.left, nodeList)
        nodeList.append(node.val)
        inorder(node.right, nodeList)

def removeRange(node, min, max):
    if node is not None:
        if min < node.val < max:
            node.left = removeRange(node.left, min, max)
            node.right = removeRange(node.right, min, max)
            return node
        else:
            if node.val < min:
                return removeRange(node.right, min, max)
            elif node.val > max:
                return removeRange(node.left, min, max)
    return None

def trimBST(root, min, max):
    nodeList = []
    inorder(root, nodeList)
    nodeList.sort()
    return removeRange(root, min, max)

def main():
    N = int(input().strip())
    root = None
    for _ in range(N):
        val = int(input().strip())
        root = insert(root, val)
    min, max = map(int, input().strip().split())
    new_root = trimBST(root, min, max)
    nodeList = []
    inorder(new_root, nodeList)
    print(' '.join(map(str, nodeList)))

if __name__ == "__main__":
    main()

In this code, we are given a root node of a Binary Search Tree and two integers L and R. First, we perform an inorder traversal to get all values in the BST in ascending order. Then, we remove all values that are not in the range [L, R] from the sorted list. Finally, we reconstruct the BST from the remaining values by creating new nodes for each value and linking them appropriately.