class Node:
    def __init__(self, left=None, right=None):
        self.left = left
        self.right = right

def build_tree(lines):
    if lines[0] == 'x':
        return None

    node = Node(build_tree(lines[1]), build_tree(lines[2]))
    return node

def depth_first_search(node, depth=0):
    if node is None:
        return
    print(f'Depth of node {node} is {depth}')
    depth_first_search(node.left, depth + 1)
    depth_first_search(node.right, depth + 1)

def main():
    N = int(input())
    lines = [input() for _ in range(N)]
    root = build_tree(lines)
    depth_first_search(root)

if __name__ == '__main__':
    main()