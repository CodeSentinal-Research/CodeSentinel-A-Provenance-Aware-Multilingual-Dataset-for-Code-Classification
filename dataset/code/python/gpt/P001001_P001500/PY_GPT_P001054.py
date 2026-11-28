# problem title : K Largest Pair Sums
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

def k_largest_pair_sums(a: List[int], b: List[int], k: int) -> List[int]:
    a.sort(reverse=True)
    b.sort(reverse=True)
    n, m = len(a), len(b)
    heap = [(-(a[0] + b[0]), 0, 0)]
    visited = {(0, 0)}
    res = []

    while heap and len(res) < k:
        neg_sum, i, j = heapq.heappop(heap)
        res.append(-neg_sum)
        if i + 1 < n and (i + 1, j) not in visited:
            heapq.heappush(heap, (-(a[i + 1] + b[j]), i + 1, j))
            visited.add((i + 1, j))
        if j + 1 < m and (i, j + 1) not in visited:
            heapq.heappush(heap, (-(a[i] + b[j + 1]), i, j + 1))
            visited.add((i, j + 1))
    return res

if __name__ == '__main__':
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    print(" ".join(map(str, k_largest_pair_sums(a, b, k))))
