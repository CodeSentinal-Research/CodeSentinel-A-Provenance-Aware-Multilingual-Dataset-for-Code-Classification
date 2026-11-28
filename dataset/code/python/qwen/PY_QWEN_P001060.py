import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    arr = list(map(int, input_data[2:2+n]))
    
    heap = []
    for i in range(min(n, k+1)):
        heapq.heappush(heap, (arr[i], i))
        
    result = []
    for i in range(n):
        val, idx = heapq.heappop(heap)
        result.append(val)
        if idx + k + 1 < n:
            heapq.heappush(heap, (arr[idx+k+1], idx+k+1))
            
    print(*result)

if __name__ == "__main__":
    solve()

