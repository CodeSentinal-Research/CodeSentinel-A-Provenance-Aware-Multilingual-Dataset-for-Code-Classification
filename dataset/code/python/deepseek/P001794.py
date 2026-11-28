Sure, here is the Python code for the problem:

class Node:
    def __init__(self, key):
        self.key  = key
        self.left = None
        self.right = None

def insert(node, key):
    if node is None:
        return Node(key)

    if key < node.key:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)

    return node

def find_LCA(node, node1, node2):
    if node is None:
        return None

    if node.key > node1 and node.key > node2:
        return find_LCA(node.left, node1, node2)

    if node.key < node1 and node.key < node2:
        return find_LCA(node.right, node1, node2)

    return node

def main():
    N = int(input().strip())
    keys = list(map(int,input().strip().split()))
    nodes = []

    for key in keys[:N]:
        nodes.append(Node(key))

    for i in range(N):
        insert(nodes[0],keys[i])

    node1 = int(input().strip())
    node2 = int(input().strip())

    lca = find_LCA(nodes[0], node1, node2)
    print(lca.key)

if __name__ == '__main__':
    main()
In this code, we first define a Node class and insert function to insert nodes into the BST. The find_LCA function is to find the Lowest Common Ancestor of two given keys. The main function reads the number of keys, inputs the keys and calls find_LCA function to print the lowest common ancestor.