Here is the Python code for the problem. 

def solve():
    n = int(input())
    tree = [None] * (n+1)
    order = []

    for i in range(n):
        line = input().split()
        if line[0] == 'root':
            tree[i+1] = (int(line[1]), int(line[2]))
        else:
            tree[i+1] = (int(line[1]), None, int(line[2]))

    for i in range(n):
        if tree[i][1] is None:
            root = i+1
        else:
            order.append(tree[i][0])

    inorder(root)
    print(' '.join(map(str, order)))


def inorder(index):
    if tree[index][1] is not None:
        inorder(tree[index][1])

    order.append(tree[index][0])

    if tree[index][2] is not None:
        inorder(tree[index][2])


if __name__ == '__main__':
    solve()

This code reads the input and constructs the Binary Search Tree (BST) in a way that lexicographically the smallest insertion sequence re-creates the BST. The `inorder` function is used to traverse the BST in an inorder manner and the resultant sequence is printed.