Here's a Python code snippet for the problem:

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def inorder(root, res):
    if not root:
        return
    inorder(root.left, res)
    res.append(root.val)
    inorder(root.right, res)

def serialize(root):
    res = []
    inorder(root, res)
    return ' '.join(map(str, res))

def deserialize(data):
    if data == '':
        return None
    vals = data.split(' ')
    root = Node(int(vals[0]))
    stack = [root]
    for num in vals[1:]:
        if num < stack[-1].val:
            stack[-1].left = Node(int(num))
            stack.append(stack[-1].left)
        else:
            while stack and stack[-1].val < int(num):
                last = stack.pop()
            last.right = Node(int(num))
            stack.append(last.right)
    return root

def main():
    root = None
    data = input()
    n = int(data.split()[0])
    for i in range(n):
        data = input().split()
        if i == 0:
            root = Node(int(data[0]))
        else:
            add_node(root, data[0])
    print(serialize(root))
    root = deserialize(serialize(root))
    for node in level_order_traversal(root):
        print(node.val, end=' ')

def add_node(root, val):
    if root is None:
        return None
    if val < root.val:
        if root.left is None:
            root.left = Node(val)
        else:
            add_node(root.left, val)
    else:
        if root.right is None:
            root.right = Node(val)
        else:
            add_node(root.right, val)

if __name__ == "__main__":
    main()

The `main` function is the entry point of the program. It reads the number of nodes, then reads the nodes. The `serialize` function serializes the tree into a string. The `deserialize` function deserializes a string back into a tree. The `add_node` function adds a node to the tree.