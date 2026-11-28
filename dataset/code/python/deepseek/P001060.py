Here is a Python code solution using the heapq module to solve the problem:

import heapq

def solve(N, K, arr):
    min_heap = [(arr[i], i) for i in range(N)]
    heapq.heapify(min_heap)

    result = []
    while min_heap:
        _, index = heapq.heappop(min_heap)
        result.append(arr[index])

        if min_heap:
            _, next_index = heapq.heappop(min_heap)
            heapq.heappush(min_heap, (arr[next_index], next_index))

    print(' '.join(map(str, result)))

N, K = map(int, input().split())
arr = list(map(int, input().split()))

solve(N, K, arr)

In this code, we create a min heap where each element is a pair of (element, index). The elements in the min heap are sorted in ascending order, and we pop elements from the heap in sorted order. This way, we ensure that the heap always has the smallest element in its root, which is the first element in the sorted list.

The time complexity of this approach is O(N log K), where N is the number of elements in the array and K is the maximum distance for an element from its correct position. The space complexity is O(N).