Here is the Python code:

import heapq

def merge_k_sorted_arrays():
    k = int(input())
    arrays = []

    for _ in range(k):
        line = list(map(int, input().split()))
        heapq.heappush(arrays, (line[0], 0))

    merged = []
    while arrays:
        smallest_array_value, idx_in_smallest_array, arrays_ref = heapq.heappop(arrays)

        if idx_in_smallest_array + 1 < len(arrays_ref):
            next_element = arrays_ref[idx_in_smallest_array + 1][0]
            heapq.heappush(arrays, (next_element, idx_in_smallest_array + 1, arrays_ref))

        merged.append(smallest_array_value)

    print(merged)


if __name__ == "__main__":
    merge_k_sorted_arrays()

In the code above, we first read the number of arrays. For each array, we push its first element and its index in the array into a heap. We then pop the smallest element, append it to the merged list, and if we have more elements in the array, we push the next element into the heap. We continue this process until we have processed all the arrays. The result is the merged list of all sorted arrays.

The heap is used because it allows for efficient removal of the smallest element. The smallest element is always at the top of the heap, and we can easily remove it and push the next smallest element into the heap.

The heap data structure is implemented in Python by default.