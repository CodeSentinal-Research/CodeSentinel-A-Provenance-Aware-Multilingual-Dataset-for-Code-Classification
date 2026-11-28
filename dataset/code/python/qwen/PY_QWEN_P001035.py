import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    
    matrix = []
    for _ in range(n):
        row = list(map(int, input_data[idx:idx+n]))
        idx += n
        matrix.append(row)
        
    # Min heap: (val, row, col)
    heap = []
    for i in range(n):
        heapq.heappush(heap, (matrix[i][0], i, 0))
        
    count = 0
    while heap:
        val, r, c = heapq.heappop(heap)
        count += 1
        if count == k:
            print(val)
            return
        if c + 1 < n:
            heapq.heappush(heap, (matrix[r][c+1], r, c+1))

if __name__ == "__main__":
    solve()

