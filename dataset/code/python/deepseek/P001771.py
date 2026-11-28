from collections import defaultdict

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def create_tree(nodes):
    node_dict = dict()
    for node in nodes:
        node_dict[node.val] = node

    for node in nodes:
        if node.left:
            node_dict[node.left.val].left = node.left
        if node.right:
            node_dict[node.right.val].right = node.right

    return node_dict[nodes[0].val]

def vertical_sum(root):
    if not root:
        return []

    column_sums = defaultdict(int)
    queue = [(root, 0)]

    while queue:
        node, column = queue.pop(0)
        column_sums[column] += node.val

        if node.left:
            queue.append((node.left, column - 1))
        if node.right:
            queue.append((node.right, column + 1))

    return [column_sums[column] for column in sorted(column_sums.keys())]

def main():
    nodes = [Node(i) for i in range(1, 6)]
    nodes[0].left = nodes[1]
    nodes[0].right = nodes[2]
    nodes[1].left = nodes[3]
    nodes[1].right = nodes[4]

    root = create_tree(nodes)
    print(vertical_sum(root))

if __name__ == '__main__':
    main()
This python code creates a binary tree using the given node values. The vertical_sum function calculates the sum of values in every vertical column. It starts by creating a defaultdict (which acts like a dictionary but with a default value) to store the sum of each column. Then it uses a queue to perform a level order traversal of the tree, where the current node and the column it is in are popped off the queue. The node's value is added to the column sum, and the left and right children of the node are added to the queue for the next iteration. Finally, it returns a list of the sums sorted by column number.