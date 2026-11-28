from typing import List
from collections import defaultdict

def count_distinct_window(arr: List[int], k: int) -> List[int]:
    count = defaultdict(int)
    res = []
    distinct = 0

    for i in range(len(arr)):
        if count[arr[i]] == 0:
            distinct += 1
        count[arr[i]] += 1

        if i >= k:
            out_val = arr[i - k]
            count[out_val] -= 1
            if count[out_val] == 0:
                distinct -= 1

        if i >= k - 1:
            res.append(distinct)

    return res

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(" ".join(map(str, count_distinct_window(arr, k))))