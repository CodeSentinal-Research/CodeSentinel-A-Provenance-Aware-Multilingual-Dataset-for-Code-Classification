Here is the Python code for the Heap Sort algorithm:

def parent(i):
    return i // 2

def leftChild(i):
    return i * 2

def rightChild(i):
    return i * 2 + 1

def heapify(arr, n, i):
    largest = i
    l = leftChild(i)
    r = rightChild(i)

    if l < n and arr[i] < arr[l]:
        largest = l

    if r < n and arr[largest] < arr[r]:
        largest = r

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]

        heapify(arr, n, largest)

def heapSort(arr):
    n = len(arr)

    for i in range(n, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

def take_input():
    n = int(input().strip())
    arr = [int(x) for x in input().strip().split()]
    return n, arr

def main():
    n, arr = take_input()
    heapSort(arr)
    print(' '.join(map(str, arr)))

if __name__ == "__main__":
    main()

The `take_input` function takes the input and return the number of elements and the array.

The `heapSort` function first builds a heap from the input array. Then it swaps the root of the heap with the last element of the array, and heaps the reduced array. This process is repeated until the array is sorted.

The `main` function calls these functions and prints the sorted array.