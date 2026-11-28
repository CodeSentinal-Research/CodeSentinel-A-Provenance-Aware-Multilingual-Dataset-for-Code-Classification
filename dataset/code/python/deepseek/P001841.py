def bst_to_list(root):
    if root is None:
        return []

    return bst_to_list(root.left) + [root.val] + bst_to_list(root.right)

def intersection(root1, root2):
    list1 = sorted(bst_to_list(root1))
    list2 = sorted(bst_to_list(root2))

    return list(set(list1) & set(list2))

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def construct_tree(nodes):
    if nodes is None:
        return None

    node = TreeNode(nodes.pop(0))
    node.left = construct_tree(nodes)
    node.right = construct_tree(nodes)

    return node

def main():
    N1 = int(input().strip())
    nodes1 = list(map(int, input().strip().split()))

    root1 = construct_tree(nodes1)

    N2 = int(input().strip())
    nodes2 = list(map(int, input().strip().split()))

    root2 = construct_tree(nodes2)

    print(intersection(root1, root2))

if __name__ == '__main__':
    main()