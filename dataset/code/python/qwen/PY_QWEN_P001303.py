import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    capital = int(input_data[idx]); idx += 1
    
    projects = []
    for _ in range(n):
        cost = int(input_data[idx]); idx += 1
        profit = int(input_data[idx]); idx += 1
        projects.append((cost, profit))
        
    projects.sort()
    max_heap = []
    i = 0
    
    for _ in range(k):
        while i < n and projects[i][0] <= capital:
            heapq.heappush(max_heap, -projects[i][1])
            i += 1
        if not max_heap:
            break
        capital += -heapq.heappop(max_heap)
        
    print(capital)

if __name__ == "__main__":
    solve()

