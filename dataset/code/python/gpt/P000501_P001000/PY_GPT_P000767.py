# problem title : Generate All Unique Binary Search Trees
# Solve the stated task using standard input and standard output.
import sys
class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val; self.left = left; self.right = right
def generate_trees(start, end):
    if start > end: return [None]
    all_trees = []
    for i in range(start, end + 1):
        left_trees = generate_trees(start, i - 1)
        right_trees = generate_trees(i + 1, end)
        for l in left_trees:
            for r in right_trees:
                all_trees.append(TreeNode(i, l, r))
    return all_trees
def serialize(root):
    if not root: return "null"
    return f"{root.val}({serialize(root.left)},{serialize(root.right)})"
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        trees = generate_trees(1, n)
        for t in trees:
            print(serialize(t))
if __name__ == '__main__':
    main()
