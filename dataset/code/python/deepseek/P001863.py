The problem is a bit complex and requires a deep understanding of Binary Search Trees (BSTs) and search tree algorithms. Here is the code for the problem:

import sys

def construct_bst(keys, frequencies, total_keys, left=0, right=None):
    if right is None:
        right = total_keys
    if left > right:
        return None
    mid = (left + right) // 2
    node = Node(keys[mid])
    node.left = construct_bst(keys, frequencies, total_keys, left, mid-1)
    node.right = construct_bst(keys, frequencies, total_keys, mid+1, right)
    return node

def calculate_search_cost(node, successful_freq, unsuccessful_freq):
    if node is None:
        return 0
    cost = node.freq * successful_freq + unsuccessful_freq
    return cost + calculate_search_cost(node.left, successful_freq, unsuccessful_freq) + calculate_search_cost(node.right, successful_freq, unsuccessful_freq)

def main():
    N = int(sys.stdin.readline().strip())
    keys = list(map(int, sys.stdin.readline().strip().split()))
    successful_freqs = list(map(int, sys.stdin.readline().strip().split()))
    unsuccessful_freqs = list(map(int, sys.stdin.readline().strip().split()))
    root = construct_bst(keys, successful_freqs, len(keys))
    cost = calculate_search_cost(root, successful_freqs[0], unsuccessful_freqs[0])
    print(cost)

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.freq = 0

if __name__ == "__main__":
    main()

In this code, we first read the input from stdin. We then construct the BST using the construct_bst function. The calculate_search_cost function is used to calculate the total search cost. The main function prints the cost.

Please note that this code assumes that the successful and unsuccessful search frequencies are the same for all keys.