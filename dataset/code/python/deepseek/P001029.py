Here is the Python code for the problem:

def min_heapify(heap, idx, heap_size):
    largest = idx
    left = 2 * idx + 1
    right = 2 * idx + 2

    if left < heap_size and heap[idx] < heap[left]:
        largest = left

    if right < heap_size and heap[largest] < heap[right]:
        largest = right

    if largest != idx:
        heap[idx], heap[largest] = heap[largest], heap[idx]
        min_heapify(heap, largest, heap_size)

def build_max_heap(heap):
    for idx in range((len(heap) - 1) // 2, -1, -1):
        min_heapify(heap, idx, len(heap))

def main():
    n = int(input())
    heap = list(map(int, input().split()))
    build_max_heap(heap)
    print(' '.join(map(str, heap)))

if __name__ == "__main__":
    main()

This code first reads the number of elements in the heap and the elements themselves. Then it builds a max heap from the input and prints the resulting heap.