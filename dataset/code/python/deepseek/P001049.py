Here's the code for the problem:

import heapq

def solve():
    N, Q = map(int, input().split())
    arr = list(map(int, input().split()))
    queries = [list(map(int, input().split())) for _ in range(Q)]

    heap = [-i for i in arr]
    heapq.heapify(heap)

    for _ in range(Q):
        idx, new_val = map(int, queries.pop(0))
        heap[idx - 1] = -new_val
        heapq.heapify(heap)

    print(*-1 * [heapq.heappop(heap) for _ in range(N)])


if __name__ == "__main__":
    solve()

In this code, we first read the input for N and Q, then the list of integers. Then we read Q pairs of index and new value, and replace the value at the given index with the new value, then heapify the heap to ensure that the heap property is maintained. Finally, we print the final heap.