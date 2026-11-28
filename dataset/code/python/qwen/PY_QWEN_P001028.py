import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    i = int(input_data[1+n])
    
    # Replace element at i with last element, pop last, then sift up/down
    last_val = arr.pop()
    if i < len(arr):
        arr[i] = last_val
        # Sift up
        curr = i
        while curr > 0:
            parent = (curr - 1) // 2
            if arr[parent] > arr[curr]: # Min heap assumption? Problem says "binary heap". Usually min unless specified.
                # Let's assume Min Heap as default for generic "heap" if not specified, or check context.
                # Previous problems specified Max/Min. This one just says "binary heap".
                # Let's assume Min Heap based on P001008/P001012.
                arr[parent], arr[curr] = arr[curr], arr[parent]
                curr = parent
            else:
                break
        # Sift down
        while True:
            left = 2 * curr + 1
            right = 2 * curr + 2
            smallest = curr
            if left < len(arr) and arr[left] < arr[smallest]:
                smallest = left
            if right < len(arr) and arr[right] < arr[smallest]:
                smallest = right
            if smallest != curr:
                arr[curr], arr[smallest] = arr[smallest], arr[curr]
                curr = smallest
            else:
                break
    print(*arr)

if __name__ == "__main__":
    solve()

