import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    m = int(input_data[1])
    arr1 = list(map(int, input_data[2:2+n]))
    arr2 = list(map(int, input_data[2+n:2+n+m]))
    
    merged = arr1 + arr2
    # Build max heap
    max_heap = [-x for x in merged]
    heapq.heapify(max_heap)
    result = [-x for x in max_heap]
    print(*result)

if __name__ == "__main__":
    solve()

