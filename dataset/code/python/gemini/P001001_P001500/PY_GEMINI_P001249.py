from typing import List
import heapq

def min_cost_connect_ropes(ropes: List[int]) -> int:
    heapq.heapify(ropes)
    total_cost = 0

    while len(ropes) > 1:
        first = heapq.heappop(ropes)
        second = heapq.heappop(ropes)
        cost = first + second
        total_cost += cost
        heapq.heappush(ropes, cost)

    return total_cost

if __name__ == '__main__':
    n = int(input())
    ropes = list(map(int, input().split()))
    print(min_cost_connect_ropes(ropes))