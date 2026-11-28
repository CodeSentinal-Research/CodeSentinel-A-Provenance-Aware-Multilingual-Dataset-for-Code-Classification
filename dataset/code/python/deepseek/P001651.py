class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def construct_tree(preorder, postorder):
    if postorder:
        root = Node(postorder.pop())
        if postorder:
            root.right = Node(postorder.pop())
        if preorder:
            root.left = construct_tree(preorder[1:], postorder)
        return root

def preorder(node):
    if node is not None:
        print(node.data, end=' ')
        preorder(node.left)
        preorder(node.right)

def postorder(node):
    if node is not None:
        postorder(node.left)
        postorder(node.right)
        print(node.data, end=' ')

def main():
    preorder_str = input().split()
    preorder_list = list(map(int, preorder_str))
    postorder_str = input().split()
    postorder_list = list(map(int, postorder_str))
    root = construct_tree(preorder_list, postorder_list)
    preorder(root)
    print()
    postorder(root)

if __name__ == "__main__":
    main()