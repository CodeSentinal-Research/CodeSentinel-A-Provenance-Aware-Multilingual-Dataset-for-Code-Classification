Here is a Python code for the problem. This code uses a depth first search approach to traverse the tree. For each node, it calculates the maximum sum of the subtree, which includes the node itself. This sum is stored in the global variable `max_sum` and updated in every recursive call.

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

max_sum = float('-inf')

def max_sum_bst(root):
    if not root:
        return 0, 0, float('inf')

    left_sum, left_bst, left_range = max_sum_bst(root.left)
    right_sum, right_bst, right_range = max_sum_bst(root.right)

    if left_bst and right_bst and left_range <= root.value <= right_range:
        current_sum = left_sum + right_sum + root.value
        global max_sum
        max_sum = max(max_sum, current_sum)
        return current_sum, True, min(left_range, right_range, root.value)

    return max(left_sum, right_sum), False, float('inf')

def main():
    N = int(input().strip())
    values = list(map(int, input().strip().split()))
    root = None
    stack = []
    for value in values:
        node = None
        while stack and (stack[-1] is not None or node is not None):
            if node is None:
                node = Node(stack.pop())
            else:
                if stack[-1] < value:
                    node.right = Node(stack.pop())
                    node = node.right
                else:
                    node.left = Node(stack.pop())
                    node = node.left
        if not root:
            root = node
    max_sum_bst(root)
    print(max_sum)

if __name__ == '__main__':
    main()

This code reads the input for the number of nodes, then the node values. It then builds a binary tree from these values. The main function then calls `max_sum_bst` to find the maximum sum of a binary search tree.