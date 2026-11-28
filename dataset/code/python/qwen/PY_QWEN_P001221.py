import sys

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def generate_trees(start, end):
    if start > end:
        return [None]
        
    all_trees = []
    for root_val in range(start, end + 1):
        left_trees = generate_trees(start, root_val - 1)
        right_trees = generate_trees(root_val + 1, end)
        
        for l in left_trees:
            for r in right_trees:
                root = TreeNode(root_val)
                root.left = l
                root.right = r
                all_trees.append(root)
                
    return all_trees

def serialize(root):
    if not root:
        return "#"
    return str(root.val) + "," + serialize(root.left) + "," + serialize(root.right)

def solve():
    n = int(sys.stdin.readline())
    trees = generate_trees(1, n)
    print(len(trees))
    # Printing all trees is complex, usually just count is required or specific format.
    # Assuming count is primary output based on similar problems.
    # If serialization is needed:
    # for t in trees:
    #     print(serialize(t))

if __name__ == "__main__":
    solve()

