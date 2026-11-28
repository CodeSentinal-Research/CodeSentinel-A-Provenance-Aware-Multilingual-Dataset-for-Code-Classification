import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    i = int(input_data[1+n])
    
    # Heapify subtree at i (Min Heap)
    def sift_down(idx):
        while True:
            left = 2 * idx + 1
            right = 2 * idx + 2
            smallest = idx
            if left < n and arr[left] < arr[smallest]:
                smallest = left
            if right < n and arr[right] < arr[smallest]:
                smallest = right
            if smallest != idx:
                arr[idx], arr[smallest] = arr[smallest], arr[idx]
                idx = smallest
            else:
                break
                
    sift_down(i)
    print(*arr)

if __name__ == "__main__":
    solve()

