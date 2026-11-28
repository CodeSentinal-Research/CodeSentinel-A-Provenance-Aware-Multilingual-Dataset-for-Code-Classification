import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    val = int(input_data[1+n])
    
    heapq.heapify(arr)
    heapq.heappush(arr, val)
    
    print(*arr)

if __name__ == "__main__":
    solve()

