from typing import List
from collections import Counter

def count_pairs_xor(arr: List[int], k: int) -> int:
    count = Counter()
    ans = 0
    for x in arr:
        ans += count[x ^ k]
        count[x] += 1
    return ans

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(count_pairs_xor(arr, k))