def check_identical(root1, root2):
    if root1 is None and root2 is None:
        return True
    elif root1 is not None and root2 is not None:
        return (root1.val == root2.val and 
                check_identical(root1.left, root2.left) and 
                check_identical(root1.right, root2.right))
    else:
        return False

def main():
    N1 = int(input().strip())
    for _ in range(N1):
        tree1 = Node(input().strip())
        if _ == N1 - 1:
            root1 = tree1
        else:
            tree1.left = Node(input().strip())
            tree1.right = Node(input().strip())

    N2 = int(input().strip())
    for _ in range(N2):
        tree2 = Node(input().strip())
        if _ == N2 - 1:
            root2 = tree2
        else:
            tree2.left = Node(input().strip())
            tree2.right = Node(input().strip())

    print('YES' if check_identical(root1, root2) else 'NO')

class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

if __name__ == "__main__":
    main()