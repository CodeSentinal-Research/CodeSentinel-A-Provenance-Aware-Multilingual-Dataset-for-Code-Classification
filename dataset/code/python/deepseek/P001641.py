Here is the Python code:

def is_subtree(root1, root2):
    if not root2:
        return True
    if not root1:
        return False
    if root1.val == root2.val:
        return is_subtree(root1.left, root2.left) and is_subtree(root1.right, root2.right)
    return False

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def build_tree(nodes_list):
    if not nodes_list:
        return None
    value = nodes_list.pop(0)
    if value == 'x':
        return None
    node = TreeNode(int(value))
    node.left = build_tree(nodes_list)
    node.right = build_tree(nodes_list)
    return node

def main():
    nodes_list1 = list(map(int, input().split()))
    nodes_list2 = list(map(int, input().split()))
    root1 = build_tree(nodes_list1)
    root2 = build_tree(nodes_list2)
    result = "YES" if is_subtree(root1, root2) else "NO"
    print(result)

if __name__ == "__main__":
    main()

This code first reads the values of the two trees from the input. The `build_tree` function builds the tree from a list of integers. The `is_subtree` function checks if a certain subtree exists in a tree. The `main` function runs the check.