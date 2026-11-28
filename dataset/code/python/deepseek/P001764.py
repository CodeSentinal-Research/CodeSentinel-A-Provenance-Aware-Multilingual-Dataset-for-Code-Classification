Here is the Python code for the problem:

def solve(index, tree):
    if index == -1:
        return (True, 0)

    left_same, left_size = solve(tree[index][0], tree)
    right_same, right_size = solve(tree[index][1], tree)

    if left_same and right_same:
        if left_size == 0:
            return (True, right_size + 1)
        elif right_size == 0:
            return (True, left_size + 1)
        else:
            if left_size > right_size:
                return (True, left_size + 1)
            else:
                return (True, right_size + 1)
    else:
        return (False, max(left_size, right_size))

def main():
    n = int(input().strip())
    tree = []
    for _ in range(n):
        line = list(map(int, input().strip().split()))
        tree.append(line)

    _, size = solve(0, tree)
    print(size)

if __name__ == "__main__":
    main()

In this code, the `solve` function is a recursive function that checks if a subtree with all values equal to the root value is larger than the largest univalue subtree. If the left and right subtrees are the same and the left subtree is larger, then the left subtree is the largest univalue subtree. Otherwise, the right subtree is the largest univalue subtree.

In the `main` function, the input is read and then the `solve` function is called with the input tree. The result is printed.