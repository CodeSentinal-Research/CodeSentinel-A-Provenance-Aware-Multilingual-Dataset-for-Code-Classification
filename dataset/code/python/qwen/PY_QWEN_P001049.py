import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    q = int(input_data[idx]); idx += 1
    arr = list(map(int, input_data[idx:idx+n])); idx += n
    
    for _ in range(q):
        i = int(input_data[idx]); idx += 1
        val = int(input_data[idx]); idx += 1
        arr[i] = val
        # Restore heap property (Min Heap)
        # Sift up
        curr = i
        while curr > 0:
            parent = (curr - 1) // 2
            if arr[parent] > arr[curr]:
                arr[parent], arr[curr] = arr[curr], arr[parent]
                curr = parent
            else:
                break
        # Sift down
        while True:
            left = 2 * curr + 1
            right = 2 * curr + 2
            smallest = curr
            if left < n and arr[left] < arr[smallest]:
                smallest = left
            if right < n and arr[right] < arr[smallest]:
                smallest = right
            if smallest != curr:
                arr[curr], arr[smallest] = arr[smallest], arr[curr]
                curr = smallest
            else:
                break
                
    print(*arr)

if __name__ == "__main__":
    solve()

