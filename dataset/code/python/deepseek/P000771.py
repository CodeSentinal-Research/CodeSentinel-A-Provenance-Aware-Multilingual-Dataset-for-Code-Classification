def optimalBST(keys, freq, i, f):
    if i > len(keys):
        return 0

    l = optimalBST(keys, freq, i, k - 1)

    r = optimalBST(keys, freq, k + 1, f)

    cost = freq[k] * (f - i + 1) + l + r

    global min_cost
    min_cost = min(min_cost, cost)

    return cost

def main():
    global min_cost
    min_cost = float('inf')

    n = int(input())
    keys = list(map(int, input().split()))
    freq = list(map(int, input().split()))

    optimalBST(keys, freq, 1, n)

    print(min_cost)

if __name__ == "__main__":
    main()

This Python solution uses a recursive approach to solve the problem. The `optimalBST` function is a recursive function that calculates the minimum search cost of a Binary Search Tree (BST) with all keys. It does this by dividing the keys into left and right subtrees. The cost of a BST is the product of the frequency of a key and the size of the left subtree (i to k-1) plus the cost of the left subtree (l) plus the cost of the right subtree (r). The minimum cost is kept track of by the global variable `min_cost`.

The `main` function handles the input, calls the `optimalBST` function with the given inputs, and prints the minimum search cost.