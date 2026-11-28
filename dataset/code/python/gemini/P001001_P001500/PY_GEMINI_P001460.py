from typing import List
from collections import defaultdict

def count_equal_xor_pairs(arr: List[int]) -> int:
    prefix = 0
    count = defaultdict(int)
    count[0] = 1
    ans = 0

    for x in arr:
        prefix ^= x
        ans += count[prefix]
        count[prefix] += 1

    return ans

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(count_equal_xor_pairs(arr))