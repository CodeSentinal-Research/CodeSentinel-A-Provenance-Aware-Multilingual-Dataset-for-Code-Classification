def parent(i):
    return i//2

def leftChild(i):
    return 2*i

def rightChild(i):
    return 2*i + 1

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

def deleteNode(arr, i):
    n = len(arr)
    arr[i] = arr[n-1]
    arr.pop()

    heapify(arr, i, 0)

def buildHeap(arr):
    for i in reversed(range(len(arr)//2)):
        heapify(arr, len(arr), i)

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    i = int(input().strip())

    buildHeap(arr)

    deleteNode(arr, i)

    print(' '.join(map(str, arr)))

if __name__ == '__main__':
    main()

This program reads the input for the number of elements `n`, a list of elements, and the index `i` to delete. It then creates a heap from the list using the `buildHeap` function. The deleted element is then moved to the last element of the list, and the list is heapified again. The heapified list is then printed to the console.