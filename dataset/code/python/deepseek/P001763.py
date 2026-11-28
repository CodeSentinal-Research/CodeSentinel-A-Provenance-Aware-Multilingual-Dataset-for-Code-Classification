Here is a Python solution for the problem:

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def count_unival_subtrees(root, count):
    if root is None:
        return True, 0

    left_unival, left_count = count_unival_subtrees(root.left, count)
    right_unival, right_count = count_unival_subtrees(root.right, count)

    if left_unival and right_unival and root.left and root.right:
        if root.left.val == root.val == root.right.val:
            count[0] += 1
            return True, 1 + left_count + right_count

    return False, left_count + right_count

def main():
    n = int(input())
    values = list(map(int, input().split()))
    tree = [TreeNode(values[i]) for i in range(n)]

    for i in range(n):
        tree[i].left = tree[2 * i + 1] if 2 * i + 1 < n else None
        tree[i].right = tree[2 * i + 2] if 2 * i + 2 < n else None

    count = [0]
    root = tree[0]
    unival_count = count_unival_subtrees(root, count)[1]

    print(unival_count)

if __name__ == "__main__":
    main()

In this code, we define a TreeNode class to represent each node in the tree. Then, we implement a recursive function `count_unival_subtrees` to count the number of univalue subtrees in a given tree. If the current node and its children are univalue subtrees, we increment the count and return True. Otherwise, we return False.

In the main function, we handle the input for the number of nodes, their values, and their connections. We then use this input to create a tree and call the `count_unival_subtrees` function to find the number of univalue subtrees in the tree. Finally, we print the number of univalue subtrees.