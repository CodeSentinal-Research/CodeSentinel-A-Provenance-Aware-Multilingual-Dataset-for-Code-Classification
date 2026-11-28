Sure, here is the Python code:

def find_height(inorder):
    if not inorder:
        return 0

    inorder_map = {inorder[i]: i for i in range(len(inorder))}
    max_val = max(inorder)
    max_idx = inorder_map[max_val]

    left_height = find_height(inorder[:max_idx])
    right_height = find_height(inorder[max_idx + 1:])

    return max(left_height, right_height) + 1

def solve(n, inorder):
    inorder = list(map(int, inorder.split()))
    inorder_map = {inorder[i]: i for i in range(n)}
    root_idx = inorder.index(max(inorder))

    left_inorder = inorder[:root_idx]
    right_inorder = inorder[root_idx + 1:]

    left_height = find_height(left_inorder)
    right_height = find_height(right_inorder)

    height = max(left_height, right_height) + 1
    return height

n, inorder = map(int, input().split())
print(solve(n, inorder))

In this code, `find_height` function is a recursive function that calculates the height of a binary search tree from a given inorder sequence. The main function `solve` handles the main logic of the problem. It reads the number of elements and the inorder sequence from the standard input, and then calls `solve` to find the height of the resulting binary search tree.