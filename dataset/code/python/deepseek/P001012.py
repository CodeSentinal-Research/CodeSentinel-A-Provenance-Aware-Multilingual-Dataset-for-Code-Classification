Here is the Python code that merges two min heaps into a single min heap:

import heapq

def merge_heaps(heap1, heap2):
    merged_heap = heap1 + heap2

    heapq.heapify(merged_heap)

    return merged_heap

def main():
    N, M = map(int, input().split())

    heap1 = list(map(int, input().split()))

    heap1 = [-i for i in heap1]
    heapq.heapify(heap1)

    heap2 = list(map(int, input().split()))
    heap2 = [-i for i in heap2]
    heapq.heapify(heap2)

    merged_heap = merge_heaps(heap1, heap2)

    print(merged_heap)

if __name__ == "__main__":
    main()

This program first reads the number of elements in the first and second heaps, then the elements themselves. These elements are then converted into heaps and merged. The merged heap is then printed.