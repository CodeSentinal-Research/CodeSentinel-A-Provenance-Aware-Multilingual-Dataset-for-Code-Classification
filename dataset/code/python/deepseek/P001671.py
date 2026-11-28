Here is the Python code for the problem:

def build_tree(nodes):
    nodes_map = {}
    for node in nodes:
        data, left, right = node.split(' ')
        nodes_map[data] = {'left': left, 'right': right}
    
    root = None
    for node in nodes:
        data, left, right = node.split(' ')
        if left == '$':
            root = data
        else:
            nodes_map[left][right] = data
    
    return root

def inorder_traversal(root):
    stack, result = [], []
    current = root
    
    while True:
        if current is not None:
            stack.append(current)
            current = nodes_map[current]['left']
        elif(stack):
            current = stack.pop()
            result.append(current)
            current = nodes_map[current]['right']
        else:
            break
    
    return result

def main():
    N = int(input())
    nodes = [input() for _ in range(N)]
    root = build_tree(nodes)
    print(' '.join(inorder_traversal(root)))

if __name__ == "__main__":
    main()

This code first constructs the tree using the input. Then it performs the inorder traversal. The input is expected to be a list of nodes, where each node is represented as a string in the format 'data left right', where 'data' is the node's value, 'left' is the left child's value, and 'right' is the right child's value.