Here is a Python solution using the Pythonic approach to create a Min Heap from an unsorted array.

def min_heapify(arr, i, n):
    smallest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[i] > arr[left]:
        smallest = left

    if right < n and arr[smallest] > arr[right]:
        smallest = right

    if smallest != i:
        arr[i], arr[smallest] = arr[smallest], arr[i]
        min_heapify(arr, smallest, n)

def build_min_heap(arr):
    n = len(arr)

    for i in range(n, -1, -1):
        min_heapify(arr, i, n)

    print(arr)

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    build_min_heap(arr)

if __name__ == "__main__":
    main()
In this solution, the `min_heapify` function is used to ensure that the array satisfies the heap property. It compares the array element at index `i` with its left and right children. If the element is smaller than either of them, it replaces the element with the smaller one and recursively calls `min_heapify` on this replaced element.

The `build_min_heap` function iterates from the last non-leaf node to the root node, calling `min_heapify` on each one. This ensures that every node in the array is in a valid heap order.

The main function reads the number of elements in the array, and the array itself. It then calls `build_min_heap` to build the Min Heap and prints the array.