from typing import List
from collections import defaultdict

def count_subarrays_xor_k(arr: List[int], k: int) -> int:
    prefix_xor = 0
    count = 0
    freq = defaultdict(int)
    freq[0] = 1
    for num in arr:
        prefix_xor ^= num
        count += freq[prefix_xor ^ k]
        freq[prefix_xor] += 1
    return count

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(count_subarrays_xor_k(arr, k))