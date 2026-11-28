# problem title : Longest Subarray with Sum K
# Solve the stated task using standard input and standard output.
from typing import List

def longest_subarray_sum_k(arr: List[int], k: int) -> int:
    seen = {0: -1}
    prefix = 0
    max_len = 0

    for i, x in enumerate(arr):
        prefix += x
        if prefix - k in seen:
            max_len = max(max_len, i - seen[prefix - k])
        if prefix not in seen:
            seen[prefix] = i

    return max_len

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(longest_subarray_sum_k(arr, k))
