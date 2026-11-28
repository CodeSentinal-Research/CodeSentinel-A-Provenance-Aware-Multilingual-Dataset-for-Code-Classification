from typing import List
import heapq

def connect_sticks(sticks: List[int]) -> int:
    heapq.heapify(sticks)
    total_cost = 0

    while len(sticks) > 1:
        s1 = heapq.heappop(sticks)
        s2 = heapq.heappop(sticks)
        cost = s1 + s2
        total_cost += cost
        heapq.heappush(sticks, cost)

    return total_cost

if __name__ == '__main__':
    n = int(input())
    sticks = list(map(int, input().split()))
    print(connect_sticks(sticks))