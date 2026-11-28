from typing import List
from collections import Counter

def count_pairs_diff(arr: List[int], k: int) -> int:
    count = Counter(arr)
    ans = 0

    if k == 0:
        for cnt in count.values():
            if cnt > 1:
                ans += 1
    else:
        for x in count:
            if x + k in count:
                ans += 1

    return ans

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(count_pairs_diff(arr, k))