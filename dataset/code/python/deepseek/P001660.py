Here is the Python code to solve the problem:

def count_nodes(node, visited):
    if not node:
        return "#"
    if node in visited:
        return visited[node]
    visited[node] = count_nodes(node.left, visited) + count_nodes(node.right, visited) + 1
    return visited[node]

def find_duplicates(node, visited, duplicate_nodes):
    if not node:
        return "#"
    left = find_duplicates(node.left, visited, duplicate_nodes)
    right = find_duplicates(node.right, visited, duplicate_nodes)
    serialized = str(node.val) + "," + left + "," + right
    if visited[serialized] > 1:
        duplicate_nodes.append(node.val)
    return serialized

def detect_duplicate_subtrees(root):
    visited = {}
    duplicate_nodes = []
    find_duplicates(root, visited, duplicate_nodes)
    return sorted(duplicate_nodes)

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def construct_tree(nodes):
    if not nodes:
        return None
    node = TreeNode(int(nodes.pop(0)))
    node.left = construct_tree(nodes)
    node.right = construct_tree(nodes)
    return node

def main():
    N = int(input().strip())
    nodes = list(map(int, input().strip().split()))
    root = construct_tree(nodes)
    print(detect_duplicate_subtrees(root))

if __name__ == "__main__":
    main()

This code first constructs a binary tree from the input. Then it calls the `detect_duplicate_subtrees` function to find all the duplicate subtrees and print them. The `detect_duplicate_subtrees` function uses a recursive approach to find the serialized representation of each subtree, and counts the number of times each serialized subtree appears. It then prints the values of all duplicate subtrees.