class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def construct_tree(pre_order, in_order, start, end):
    if start > end:
        return None
    node = Node(pre_order[construct_tree.index])
    construct_tree.index += 1
    if start == end:
        return node
    i_index = in_order.index(node.data)
    node.left = construct_tree(pre_order, in_order, start, i_index - 1)
    node.right = construct_tree(pre_order, in_order, i_index + 1, end)
    return node

def largest_bst(root):
    if not root:
        return (0, 0, 0, True)
    left = largest_bst(root.left)
    right = largest_bst(root.right)
    if not left[2] or not right[2] or root.data <= left[0] or root.data >= right[0]:
        return (0, 0, 0, False)
    best_bst = (max(left[0], right[0], root.data), left[1] + 1 + right[1], left[3] or right[3], max(left[1], right[1]) + 1
    return best_bst

def main():
    pre_order = list(map(int, input().split()))
    construct_tree.index = 0
    root = construct_tree(pre_order, list(map(int, input().split())), 0, len(pre_order) - 1)
    print(largest_bst(root)[0])

main()