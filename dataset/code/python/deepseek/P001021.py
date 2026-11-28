def increaseKey(heap, i, newValue):
    if i < 0 or i >= len(heap):
        raise Exception('Invalid index')

    heap[i] = newValue

    while i > 0 and heap[i] > heap[(i-1)//2]:
        heap[i], heap[(i-1)//2] = heap[(i-1)//2], heap[i]
        i = (i-1)//2

def buildMaxHeap(heap):
    for i in range(len(heap), -1, -1):
        maxHeapify(heap, i)

def maxHeapify(heap, i):
    left = 2*i + 1
    right = 2*i + 2
    largest = i

    if left < len(heap) and heap[left] > heap[largest]:
        largest = left

    if right < len(heap) and heap[right] > heap[largest]:
        largest = right

    if largest != i:
        heap[i], heap[largest] = heap[largest], heap[i]
        maxHeapify(heap, largest)

def printHeap(heap):
    for i in range(len(heap)):
        print(heap[i], end=' ')
    print()

def main():
    n = int(input().strip())
    heap = list(map(int, input().strip().split()))
    i, newValue = map(int, input().strip().split())

    increaseKey(heap, i, newValue)

    printHeap(heap)

if __name__ == '__main__':
    main()