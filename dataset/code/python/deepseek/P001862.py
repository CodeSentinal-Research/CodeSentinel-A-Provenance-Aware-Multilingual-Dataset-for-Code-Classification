Sure, here is the python code:

def find_optimal_cost(keys, frequencies):
    n = len(keys)
    prefix_sum = [0] * (n + 1)
    for i in range(n):
        prefix_sum[i+1] = prefix_sum[i] + frequencies[i]
    total_freq = sum(frequencies)

    min_cost = float('inf')
    min_bst = None

    for i in range(n):
        left_freq = prefix_sum[i]
        right_freq = total_freq - left_freq
        cost = abs(left_freq - right_freq) * keys[i]
        if cost < min_cost:
            min_cost = cost
            min_bst = (left_freq, right_freq, keys[i])

    return min_cost, min_bst

def construct_bst(bst):
    keys, left_freq, right_freq, x = bst
    print(f'Construct the BST:')
    print(f'  Node {x}')
    print(f'    Node {keys[0]} (left child)')
    print(f'    Node {keys[-1]} (right child)')
    print(f'    The left subtree is:')
    construct_bst((keys[0], left_freq, sum(left_freq), keys[0]))
    print(f'    The right subtree is:')
    construct_bst((keys[-1], sum(left_freq) - left_freq, right_freq, keys[-1]))

def main():
    n = int(input().strip())
    keys = list(map(int, input().strip().split()))
    frequencies = list(map(int, input().strip().split()))

    cost, bst = find_optimal_cost(keys, frequencies)
    print(f'Minimum expected search cost is: {cost}')
    print('The constructed Optimal BST is:')
    construct_bst(bst)

if __name__ == '__main__':
    main()

This code first calculates the prefix sum of frequencies, and then iterates over the keys to find the minimum cost. It also constructs and prints the optimal binary search tree.