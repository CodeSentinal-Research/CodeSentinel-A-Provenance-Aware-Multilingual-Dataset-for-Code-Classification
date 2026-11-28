Here is the Python code for the given problem:

def print_heap(heap):
    print(' '.join(map(str, heap)))

def delete_root(heap):
    heap[0] = heap[-1]
    heap.pop()
    i = 0
    while i < len(heap) and heap[i] > heap[left_child(i)]:
        heap[i], heap[left_child(i)] = heap[left_child(i)], heap[i]
        i = left_child(i)
    while i < len(heap) and heap[i] > heap[right_child(i)]:
        heap[i], heap[right_child(i)] = heap[right_child(i)], heap[i]
        i = right_child(i)

def left_child(i):
    return 2 * i + 1

def right_child(i):
    return 2 * i + 2

def heapify(heap, i):
    left_child_index = left_child(i)
    right_child_index = right_child(i)
    largest = i

    if left_child_index < len(heap) and heap[left_child_index] > heap[largest]:
        largest = left_child_index

    if right_child_index < len(heap) and heap[right_child_index] > heap[largest]:
        largest = right_child_index

    if largest != i:
        heap[i], heap[largest] = heap[largest], heap[i]
        heapify(heap, largest)

def build_heap(heap):
    start_index = len(heap) // 2 - 1  
    for i in range(start_index, -1, -1):
        heapify(heap, i)

def main():
    n = int(input().strip())
    heap = list(map(int, input().strip().split()))
    build_heap(heap)
    print_heap(heap)
    delete_root(heap)
    print_heap(heap)

if __name__ == "__main__":
    main()

This code first builds the heap from the input array, then it prints the heap after deletion, and finally the heap after the deletion. The `delete_root` function first swaps the root with the last element in the heap, then it removes the last element (the root), and then it heaps the root back up by swapping it with its smaller child if necessary.

The `heapify` function is used to maintain the heap property after a node is deleted. If the node is a leaf node, it does nothing. If the node is a non-leaf node, it swaps it with its larger child if necessary, and recursively calls `heapify` on the swapped node.

The `build_heap` function is used to rebuild the heap by fixing the heap property starting from the last non-leaf node (which is the last node in the array) to the root.

The `main` function reads the number of elements in the heap, the heap itself, and then it calls the necessary functions to print the heap after deletion and restore the heap property.