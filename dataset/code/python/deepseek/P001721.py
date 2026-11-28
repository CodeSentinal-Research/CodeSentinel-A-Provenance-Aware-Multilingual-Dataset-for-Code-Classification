Here is the Python code for your problem:

def is_leaf(node):
    return node.left is None and node.right is None

def sum_of_nodes_at_odd_levels(root):
    sum = 0
    queue = [(root, 0)]
    while queue:
        node, level = queue.pop(0)
        if node:
            if is_leaf(node) and level % 2 == 1:
                sum += node.val
            queue.extend([(node.left, level + 1), (node.right, level + 1)])
    return sum

The code works by using a queue to traverse the tree level by level. We start by adding the root node to the queue with level 0. Then, while the queue is not empty, we pop a node and its level from the queue. If the node is not None, we check if it's a leaf node and the level is odd. If it is, we add its value to the sum. We then add its children to the queue with the level incremented by 1.