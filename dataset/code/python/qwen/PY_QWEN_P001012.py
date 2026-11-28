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
    heapq.heapify(merged)
    
    print(*merged)

if __name__ == "__main__":
    solve()

