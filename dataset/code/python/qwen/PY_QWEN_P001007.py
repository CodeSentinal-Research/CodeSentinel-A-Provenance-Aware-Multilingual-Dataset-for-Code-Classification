import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    new_val = int(input_data[1+n])
    
    # Replace root and restore max heap property
    # Since heapq is min-heap, we invert values for max-heap simulation
    max_heap = [-x for x in arr]
    heapq.heapify(max_heap)
    
    # Remove old root (largest) and push new value
    # Actually, problem says replace root. 
    # In array representation, root is index 0.
    # We can just set arr[0] = new_val and sift down.
    
    arr[0] = new_val
    
    def sift_down(idx):
        while True:
            left = 2 * idx + 1
            right = 2 * idx + 2
            largest = idx
            
            if left < n and arr[left] > arr[largest]:
                largest = left
            if right < n and arr[right] > arr[largest]:
                largest = right
                
            if largest != idx:
                arr[idx], arr[largest] = arr[largest], arr[idx]
                idx = largest
            else:
                break
                
    sift_down(0)
    print(*arr)

if __name__ == "__main__":
    solve()

