Here is the Python code for the problem:

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def reconstruct(pre, inorder):
    if pre == []:
        return None

    root = Node(pre[0])

    index = inorder.index(pre[0])

    left_inorder = inorder[0:index]
    right_inorder = inorder[index+1:]
    left_pre = pre[1:len(left_inorder)+1]
    right_pre = pre[len(left_inorder)+1:]

    root.left = reconstruct(left_pre, left_inorder)
    root.right = reconstruct(right_pre, right_inorder)

    return root

def print_level_order(root):
    if root is None:
        return

    queue = []
    queue.append(root)

    while(len(queue) > 0):
        print (queue[0].data, end = " ")
        node = queue.pop(0)

        if node.left is not None:
            queue.append(node.left)
        if node.right is not None:
            queue.append(node.right)

def main():
    pre = list(map(int, input().split()))
    inorder = list(map(int, input().split()))

    root = reconstruct(pre, inorder)

    print_level_order(root)

if __name__ == "__main__":
    main()

In this code, we first define a class `Node` to represent each node of the binary tree. We create a function `reconstruct` to reconstruct the tree from the given preorder and inorder traversals. In the `reconstruct` function, we first check if the preorder list is empty. If it is, we return None because we have reached a leaf node. If not, we create a new node with the first element of the preorder list and find the index of this node in the inorder list. Then, we divide the inorder list into left and right subtrees and the preorder list into left and right subtrees. We recursively call `reconstruct` for the left and right subtrees with the appropriate preorder and inorder lists. Finally, we print the level order traversal of the reconstructed tree.