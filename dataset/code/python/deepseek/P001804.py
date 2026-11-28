def check_bst(s1, s2):
    if len(s1) != len(s2):
        return False
    if len(s1) == 0:
        return True

    root1 = sorted_list_to_bst(s1)
    root2 = sorted_list_to_bst(s2)

    return bst_to_sorted_list(root1) == bst_to_sorted_list(root2)


def sorted_list_to_bst(s):
    if not s:
        return None

    mid = len(s) // 2

    root = TreeNode(s[mid])

    root.left = sorted_list_to_bst(s[:mid])
    root.right = sorted_list_to_bst(s[mid + 1 :])

    return root


def bst_to_sorted_list(root):
    if not root:
        return []

    return (bst_to_sorted_list(root.left) + [root.val] +
            bst_to_sorted_list(root.right))


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def main():
    n = int(input().strip())
    s1 = list(map(int, input().strip().split()))
    s2 = list(map(int, input().strip().split()))

    print("YES" if check_bst(s1, s2) else "NO")


if __name__ == "__main__":
    main()