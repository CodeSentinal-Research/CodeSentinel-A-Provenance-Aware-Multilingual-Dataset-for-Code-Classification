class Node:
    def __init__(self, value=None, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def is_even_odd_tree(root):
    even_depth = [root]
    odd_depth = []

    while even_depth or odd_depth:
        new_even_depth = []
        new_odd_depth = []

        for node in even_depth:
            if node.value % 2 == 0 or (node.left and node.left.value % 2 == 0 and node.right and node.right.value % 2 == 0):
                return 'NO'
            if node.left:
                new_odd_depth.append(node.left)
            if node.right:
                new_odd_depth.append(node.right)

        for node in odd_depth:
            if node.value % 2 == 1 or (node.left and node.left.value % 2 == 1 and node.right and node.right.value % 2 == 1):
                return 'NO'
            if node.left:
                new_even_depth.append(node.left)
            if node.right:
                new_even_depth.append(node.right)

        even_depth = new_even_depth
        odd_depth = new_odd_depth

    return 'YES'

def main():
    N = int(input().strip())

    nodes = [None] * (2 * N + 2)
    for i in range(1, N + 1):
        value = int(input().strip())
        nodes[i] = Node(value)
        if i % 2 == 1:
            nodes[i // 2].right = nodes[i]
        else:
            nodes[i // 2].left = nodes[i]

    root = nodes[1]
    print(is_even_odd_tree(root))

if __name__ == '__main__':
    main()