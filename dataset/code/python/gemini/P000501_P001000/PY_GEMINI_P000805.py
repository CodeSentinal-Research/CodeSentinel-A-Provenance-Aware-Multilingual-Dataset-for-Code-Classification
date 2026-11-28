from typing import List
from collections import defaultdict

def count_equal_pos_neg_subarrays(arr: List[int]) -> int:
    prefix_sum = 0
    count = 0
    freq = defaultdict(int)
    freq[0] = 1
    for x in arr:
        val = 1 if x > 0 else (-1 if x < 0 else 0)
        prefix_sum += val
        count += freq[prefix_sum]
        freq[prefix_sum] += 1
    return count

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(count_equal_pos_neg_subarrays(arr))