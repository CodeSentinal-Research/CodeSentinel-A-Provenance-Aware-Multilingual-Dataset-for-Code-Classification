Here is the Python code for the given problem:

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def build_tree(nodes):
    root = None
    q = []
    for node_data in nodes:
        if node_data == -1:
            q.append(None)
        else:
            node = Node(node_data)
            if root is None:
                root = node
            else:
                q.append(node)
                if q.index(node) % 2 == 0:
                    q[q.index(node) - 1].left = node
                else:
                    q[q.index(node) - 1].right = node
            q[q.index(node)]
    return root

def check_siblings(root, node1, node2):
    if root is None:
        return False
    if root.left == node1 and root.right == node2:
        return True
    else:
        return check_siblings(root.left, node1, node2) or check_siblings(root.right, node1, node2)

def main():
    N = int(input().strip())
    nodes = list(map(int, input().strip().split()))[:N]
    root = build_tree(nodes)
    node1, node2 = map(int, input().strip().split())
    result = 'YES' if check_siblings(root, Node(node1), Node(node2)) else 'NO'
    print(result)

if __name__ == '__main__':
    main()

This code first reads the number of nodes and the nodes of the binary tree. Then it reads the two nodes to check if they are siblings. The `build_tree` function builds the binary tree from the input data. The `check_siblings` function checks if two nodes are siblings in the binary tree.