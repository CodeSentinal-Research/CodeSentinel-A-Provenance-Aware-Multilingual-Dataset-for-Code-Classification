class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert_node(node, data):
    if node is None:
        return Node(data)
    else:
        if node.data < data:
            node.right = insert_node(node.right, data)
        else:
            node.left = insert_node(node.left, data)
    return node

def find_ancestors(node, target, path=None):
    if node is None:
        return None
    if node.data == target:
        return path
    if node.data < target:
        return find_ancestors(node.right, target, path + [node.data])
    else:
        return find_ancestors(node.left, target, path + [node.data])

def find_cousins(root, target):
    ancestors = find_ancestors(root, target)
    if ancestors is None:
        return None
    cousin_nodes = [node.data for node in ancestors[1:]]
    return cousin_nodes

def main():
    N = int(input())
    data = list(map(int, input().split()))
    root = None
    for i in range(N):
        root = insert_node(root, data[i])
    target = int(input())
    cousin_nodes = find_cousins(root, target)
    if cousin_nodes is None:
        print('None')
    else:
        print(cousin_nodes)

if __name__ == "__main__":
    main()