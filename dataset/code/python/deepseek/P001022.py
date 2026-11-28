def heapify(arr, n, i):
    smallest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[i] > arr[left]:
        smallest = left

    if right < n and arr[smallest] > arr[right]:
        smallest = right

    if smallest != i:
        arr[i], arr[smallest] = arr[smallest], arr[i]
        print('Swap arr[{}]:{} and arr[{}]:{}'.format(i, arr[i], smallest, arr[smallest]))
        heapify(arr, n, smallest)

def decreaseKey(arr, i, newVal):
    if newVal < arr[i]:
        print('New value is smaller than current key')
        return

    arr[i] = newVal
    print('Update arr[{}]:{} to arr[{}]:{}'.format(i, arr[i], i, newVal))

    while i != 0 and arr[i] < arr[(i-1)/2]:
        arr[(i-1)/2], arr[i] = arr[i], arr[(i-1)/2]
        i = (i-1)/2

    print('Print updated heap: ', arr)

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    i = int(input().strip())
    newVal = int(input().strip())
    decreaseKey(arr, i, newVal)

if __name__ == "__main__":
    main()