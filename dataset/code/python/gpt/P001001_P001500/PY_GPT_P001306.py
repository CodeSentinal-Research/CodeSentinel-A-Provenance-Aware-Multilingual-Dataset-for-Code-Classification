# problem title : Optimal File Merge Pattern
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

def optimal_merge(files: List[int]) -> int:
    heapq.heapify(files)
    total_cost = 0

    while len(files) > 1:
        f1 = heapq.heappop(files)
        f2 = heapq.heappop(files)
        cost = f1 + f2
        total_cost += cost
        heapq.heappush(files, cost)

    return total_cost

if __name__ == '__main__':
    n = int(input())
    files = list(map(int, input().split()))
    print(optimal_merge(files))
