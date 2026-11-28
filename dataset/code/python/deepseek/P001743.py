from collections import deque

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def find_first_non_full_node(root):
    if root is None:
        return None

    queue = deque([root])

    while queue:
        node = queue.popleft()
        if node.left is None and node.right:
            return node.val
        if node.left and node.right:
            queue.append(node.left)
            queue.append(node.right)
        elif node.left:
            queue.append(node.left)
        elif node.right:
            queue.append(node.right)

    return None

def create_binary_tree(node_list):
    if not node_list:
        return None

    root = Node(node_list[0])
    queue = deque([root])
    index = 1

    while queue and index < len(node_list):
        current_node = queue.popleft()
        if node_list[index] is not None:
            current_node.left = Node(node_list[index])
            queue.append(current_node.left)
        index += 1
        if index >= len(node_list):
            break
        if node_list[index] is not None:
            current_node.right = Node(node_list[index])
            queue.append(current_node.right)
        index += 1

    return root

def main():
    N = int(input().strip())
    node_list = list(map(int, input().strip().split()))
    root = create_binary_tree(node_list)
    first_non_full_node = find_first_non_full_node(root)
    print(first_non_full_node)

if __name__ == "__main__":
    main()