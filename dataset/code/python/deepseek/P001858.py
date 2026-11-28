Sure, here is the Python code:

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def level_order_input():
    n = int(input().strip())
    values = list(map(int, input().strip().split()))
    return n, values

def reconstruct_tree(values):
    if not values:
        return None
    
    root = Node(values[0])
    queue = [root]
    index = 0
    
    while index < len(values):
        current_node = queue.pop(0)
        
        if index + 1 < len(values) and values[index + 1] < values[0]:
            current_node.left = Node(values[index + 1])
            queue.append(current_node.left)
        else:
            if index + 1 < len(values) and values[index + 1] >= values[0]:
                current_node.left = Node(values[index + 1])
                queue.append(current_node.left)
            index += 1
            
        if index + 1 < len(values) and values[index + 1] < values[0]:
            current_node.right = Node(values[index + 1])
            queue.append(current_node.right)
        else:
            if index + 1 < len(values) and values[index + 1] >= values[0]:
                current_node.right = Node(values[index + 1])
                queue.append(current_node.right)
            index += 1
    
    return root

def pre_order_traversal(node):
    if node is not None:
        print(node.key, end=' ')
        pre_order_traversal(node.left)
        pre_order_traversal(node.right)

def main():
    n, values = level_order_input()
    root = reconstruct_tree(values)
    pre_order_traversal(root)

if __name__ == "__main__":
    main()

In this code, we first define a `Node` class to represent each node in the binary search tree. Then, we define two functions `level_order_input` and `reconstruct_tree` to handle the input and reconstruct the binary search tree from the level order traversal. Finally, we define a `pre_order_traversal` function to print the keys of the binary search tree in pre-order traversal.