# problem title : Longest Subarray with Equal Positive and Negative Elements
# Solve the stated task using standard input and standard output.
from typing import List

def max_len_equal_pos_neg(arr: List[int]) -> int:
    prefix_map = {0: -1}
    prefix_sum = 0
    max_len = 0
    for i, x in enumerate(arr):
        val = 1 if x > 0 else (-1 if x < 0 else 0)
        prefix_sum += val
        if prefix_sum in prefix_map:
            max_len = max(max_len, i - prefix_map[prefix_sum])
        else:
            prefix_map[prefix_sum] = i
    return max_len

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(max_len_equal_pos_neg(arr))
