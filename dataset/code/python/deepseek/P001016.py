Here's the Python code for the problem:

import heapq

def sliding_window_max(arr, k):
    max_heap = []
    for i in range(len(arr)):
        if max_heap and max_heap[0] < -arr[i]:
            heapq.heappop(max_heap)
        heapq.heappush(max_heap, -arr[i])
        if i >= k-1:
            print(-max_heap[0])

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    sliding_window_max(arr, K)

if __name__ == "__main__":
    main()

In this code, we use a max heap to keep track of the maximum element in the current window. The max heap will always keep the largest element in the current window, so whenever we get to the end of the window and need to check the next window, we pop the max element from the heap.

The main function first reads the input, then calls the sliding_window_max function with the input.

The time complexity is O(n log k) because we need to pop and push elements to the heap, and we do this k times (each iteration over n elements). The space complexity is O(k) for the max heap.