def sift_down(heap, index, size):
    left = 2 * index + 1
    right = 2 * index + 2
    smallest = index

    if left < size and heap[left] < heap[smallest]:
        smallest = left

    if right < size and heap[right] < heap[smallest]:
        smallest = right

    if smallest != index:
        heap[index], heap[smallest] = heap[smallest], heap[index]
        sift_down(heap, smallest, size)

def build_heap(heap):
    for i in range((len(heap) - 1) // 2, -1, -1):
        sift_down(heap, i, len(heap))

def heapify_subtree(heap, i):
    build_heap(heap)
    sift_down(heap, i, len(heap))

def main():
    size = int(input())
    heap = [int(x) for x in input().split()]
    i = int(input())

    print('Before:', heap)
    heapify_subtree(heap, i)
    print('After:', heap)

if __name__ == "__main__":
    main()

This code first reads the size of the heap and the heap itself. Then it reads the index of the subtree root to be heapified. The `build_heap` function is used to build the heap, and the `sift_down` function is used to restore the heap property. The `heapify_subtree` function uses `build_heap` and `sift_down` to heapify the subtree rooted at index `i`. In the main function, it reads the heap, the index of the subtree root to be heapified, and prints the updated heap.