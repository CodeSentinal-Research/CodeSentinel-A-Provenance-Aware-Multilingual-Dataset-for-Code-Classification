from typing import List
import heapq

def min_cost_ropes(arr: List[int]) -> int:
    heapq.heapify(arr)
    total_cost = 0
    while len(arr) > 1:
        first = heapq.heappop(arr)
        second = heapq.heappop(arr)
        cost = first + second
        total_cost += cost
        heapq.heappush(arr, cost)
    return total_cost

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(min_cost_ropes(arr))