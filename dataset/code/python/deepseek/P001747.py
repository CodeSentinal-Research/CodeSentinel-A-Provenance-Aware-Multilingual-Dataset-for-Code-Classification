class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def create_tree(nodes):
    nodes = list(map(int, nodes))
    nodes.append(-1)
    index = 0
    root = None

    while index < len(nodes):
        if nodes[index] is not -1:
            node = Node(nodes[index])
            if root is None:
                root = node
            else:
                queue = [root]
                while queue:
                    temp = queue.pop(0)
                    if temp.left is None:
                        temp.left = node
                        break
                    else:
                        queue.append(temp.left)
                    if temp.right is None:
                        temp.right = node
                        break
                    else:
                        queue.append(temp.right)
            index += 1
        else:
            nodes[index - 1] = -1
            index -= 1
    return root

def max_leaves_level(root):
    max_leaf_nodes = 0
    max_leaf_level = None
    max_leaf_count = 0
    queue = [(root, 0)]

    while queue:
        node, level = queue.pop(0)
        if node.left is None and node.right is None:
            if max_leaf_count == 0:
                max_leaf_nodes = level
                max_leaf_count += 1
            elif max_leaf_count > 0 and level == max_leaf_level:
                max_leaf_count += 1
            else:
                max_leaf_level = level
                max_leaf_count = 1
        if node.left:
            queue.append((node.left, level + 1))
        if node.right:
            queue.append((node.right, level + 1))

    return max_leaf_level if max_leaf_count > 0 else None

def main():
    n = int(input().strip())
    nodes = input().strip().split(' ')
    root = create_tree(nodes)
    print(max_leaves_level(root))

main()