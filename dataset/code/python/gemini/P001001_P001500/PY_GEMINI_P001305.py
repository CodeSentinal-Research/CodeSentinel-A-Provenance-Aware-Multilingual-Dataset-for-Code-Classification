from typing import List
import heapq

def huffman_cost(freq: List[int]) -> int:
    heapq.heapify(freq)
    total_cost = 0

    while len(freq) > 1:
        f1 = heapq.heappop(freq)
        f2 = heapq.heappop(freq)
        cost = f1 + f2
        total_cost += cost
        heapq.heappush(freq, cost)

    return total_cost

if __name__ == '__main__':
    n = int(input())
    freq = list(map(int, input().split()))
    print(huffman_cost(freq))