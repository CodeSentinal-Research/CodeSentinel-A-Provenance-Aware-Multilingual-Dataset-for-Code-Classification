from collections import deque

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def create_tree(nodes):
    nodes_dict = dict()
    for node in nodes:
        if node is not None:
            nodes_dict[node] = Node(node)
            if node * 2 in nodes:
                nodes_dict[node].left = nodes_dict[node * 2]
            if node * 2 + 1 in nodes:
                nodes_dict[node].right = nodes_dict[node * 2 + 1]
    return nodes_dict

def level_order_traversal(root):
    queue = deque([root])
    while queue:
        node = queue.popleft()
        print(node.value, end=' ')
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)

def find_median(root):
    level_order_traversal(root)

def main():
    N = int(input())
    nodes = list(map(int, input().split()))
    nodes = [None] + nodes
    root = create_tree(nodes)[1]
    find_median(root)

main()