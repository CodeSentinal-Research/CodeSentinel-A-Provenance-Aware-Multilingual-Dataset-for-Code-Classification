import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    a = list(map(int, input_data[idx:idx+n])); idx += n
    b = list(map(int, input_data[idx:idx+n])); idx += n
    
    a.sort(reverse=True)
    b.sort(reverse=True)
    
    # Max heap for pair sums
    # Start with largest pairs
    heap = [(-(a[0] + b[0]), 0, 0)]
    visited = set([(0,0)])
    result = []
    
    for _ in range(k):
        neg_sum, i, j = heapq.heappop(heap)
        result.append(-neg_sum)
        
        if i + 1 < n and (i+1, j) not in visited:
            heapq.heappush(heap, (-(a[i+1] + b[j]), i+1, j))
            visited.add((i+1, j))
        if j + 1 < n and (i, j+1) not in visited:
            heapq.heappush(heap, (-(a[i] + b[j+1]), i, j+1))
            visited.add((i, j+1))
            
    print(*result)

if __name__ == "__main__":
    solve()

