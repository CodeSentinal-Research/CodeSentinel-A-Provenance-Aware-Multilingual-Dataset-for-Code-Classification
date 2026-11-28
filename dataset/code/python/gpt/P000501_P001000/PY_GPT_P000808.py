# problem title : Maximum Length Subarray with Equal Even and Odd Numbers
# Solve the stated task using standard input and standard output.
from typing import List

def max_len_equal_even_odd(arr: List[int]) -> int:
    prefix_map = {0: -1}
    prefix = 0
    max_len = 0
    for i, x in enumerate(arr):
        prefix += 1 if x % 2 == 0 else -1
        if prefix in prefix_map:
            max_len = max(max_len, i - prefix_map[prefix])
        else:
            prefix_map[prefix] = i
    return max_len

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(max_len_equal_even_odd(arr))
