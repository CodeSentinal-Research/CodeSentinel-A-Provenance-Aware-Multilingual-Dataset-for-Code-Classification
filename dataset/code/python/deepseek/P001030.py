Here's the Python code for the problem:

import heapq

def min_heapify(arr):
    heapq.heapify(arr)
    return arr

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    min_heap = min_heapify(arr)
    print(*min_heap)

if __name__ == "__main__":
    main()

This code takes the first line of the input, `n`, which is the number of elements in the heap. Then, it takes the next `n` lines, each containing one element of the heap, and stores them in the `arr` list. Finally, it calls the `min_heapify` function to convert `arr` into a min heap, and prints the resulting min heap.