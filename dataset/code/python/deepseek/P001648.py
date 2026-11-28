Here is the Python solution for the problem:

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def serialize(root):
    if not root:
        return 'N '
    result = [str(root.val) + ' ']
    result += serialize(root.left)
    result += serialize(root.right)
    return result

def deserialize(serialized):
    value = next(serialized)
    if value == 'N ':
        return None
    node = Node(int(value))
    node.left = deserialize(serialized)
    node.right = deserialize(serialized)
    return node

def main():
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    serialized = serialize(root)
    print('Serialized:', ' '.join(serialized))

    deserialized = deserialize(iter(serialized))
    print('Deserialized:', post_order(deserialized))

def post_order(node):
    if node is None:
        return ''
    return post_order(node.left) + post_order(node.right) + str(node.val) + ' '

if __name__ == '__main__':
    main()

This code defines a Node class and a serialize and deserialize function. The serialize function takes a root of a tree and returns the serialized representation of the tree. The deserialize function takes a generator representing the serialized tree and returns the root of the deserialized tree. The post_order function is a helper function that returns the post-order traversal of a tree.

The main function creates a binary tree and prints the serialized and deserialized representations.

Please note that this code assumes that the input is a well-formed serialized tree. If the input could be malformed, you would need to add error checking to handle those cases.