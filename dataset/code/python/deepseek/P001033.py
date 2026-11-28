Here is a Python solution using a min heap.

import heapq

def find_k_smallest(arr, k):
    min_heap = [-abs(x) for x in arr[:k]]
    heapq.heapify(min_heap)

    for i in range(k, len(arr)):
        if -abs(arr[i]) < min_heap[0]:
            heapq.heappop(min_heap)
            heapq.heappush(min_heap, -abs(arr[i]))

    for i in min_heap:
        print(-i)


def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    find_k_smallest(arr, k)


if __name__ == "__main__":
    main()

The code first builds a min heap of the first K elements. Then for the rest of the array, if a new element is smaller than the smallest element in the heap, it pops the smallest element from the heap and pushes the new element. The smallest K elements in the heap are the K smallest elements.

The `main` function handles the input and calls the `find_k_smallest` function to find the K smallest elements.