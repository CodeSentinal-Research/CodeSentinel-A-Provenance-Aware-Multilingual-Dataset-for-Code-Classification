Here is the Python code for the given problem:

def minCost(inorder, start, end):
    if start >= end:
        return 0

    max_index = index_of_max(inorder, start, end)

    left = minCost(inorder, start, max_index)
    right = minCost(inorder, max_index + 1, end)

    return (inorder[max_index] * min(left, right)) + sum(inorder[start:max_index] + inorder[max_index + 1:end])


def index_of_max(inorder, start, end):
    max_index = start
    max_value = inorder[start]
    for i in range(start + 1, end):
        if inorder[i] > max_value:
            max_value = inorder[i]
            max_index = i
    return max_index


if __name__ == '__main__':
    n = int(input().strip())
    inorder = list(map(int, input().strip().split()))
    print(minCost(inorder, 0, len(inorder)))

In this code, we first define a function `minCost` that computes the minimum cost of the non-leaf nodes. It uses recursion to divide and conquer the tree.

The function `index_of_max` is a helper function that returns the index of the maximum element in the given range.

The main part of the code reads the number of leaf nodes, and the inorder traversal of the leaf nodes. It then calls `minCost` with these values.