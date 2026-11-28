Here is the Python code for the problem.

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def build_tree(nodes):
    root = None
    if nodes:
        data = nodes.pop(0)
        if data == -1:
            return None
        root = Node(data)
        root.left = build_tree(nodes)
        root.right = build_tree(nodes)
    return root

def pre_order(root):
    if root:
        print(root.data, end=' ')
        pre_order(root.left)
        pre_order(root.right)

def is_identical(a, b):
    if a is None and b is None:
        return True
    if a is None or b is None:
        return False
    if a.data != b.data:
        return False
    return is_identical(a.left, b.left) and is_identical(a.right, b.right)

def is_subtree(T1, T2):
    if T2 is None:
        return True
    if T1 is None:
        return False
    if is_identical(T1, T2):
        return True
    return is_subtree(T1.left, T2) or is_subtree(T1.right, T2)

def main():
    N = int(input().strip())
    nodes = list(map(int, input().strip().split()))
    nodes_rev = [None] * (2 * N + 1)
    for i in range(N):
        nodes_rev[2 * i + 1] = nodes[N - 1 - i]
        nodes_rev[2 * i + 2] = -1
    tree = build_tree(nodes_rev)
    if is_subtree(tree, build_tree(nodes)):
        print("YES")
    else:
        print("NO")

if __name__ == '__main__':
    main()

This code will take the input of N followed by N space-separated integers, and then the N-2 integers -1 and N-2 space-separated integers. It then creates two binary trees. The first tree is created from the input list in a way that it mirrors the original tree. Then it checks if the second tree is a subtree of the first tree. If it is, it prints "YES"; otherwise, it prints "NO".

Please note that the input should be in the following format:

N
N1 N2 N3 ... NN
N1 N2 N3 ... NN -1 -1 ... -1

where N is the number of nodes in the tree, N1, N2, ..., NN are the data of the nodes, and -1 is used to represent the null node.