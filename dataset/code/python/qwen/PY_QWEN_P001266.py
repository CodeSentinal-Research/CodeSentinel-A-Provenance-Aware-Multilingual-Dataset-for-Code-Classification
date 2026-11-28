import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    capital = list(map(int, input_data[idx:idx+n])); idx += n
    profits = list(map(int, input_data[idx:idx+n])); idx += n
    w = int(input_data[idx]); idx += 1
    
    projects = sorted(zip(capital, profits))
    max_heap = []
    i = 0
    
    for _ in range(k):
        while i < n and projects[i][0] <= w:
            heapq.heappush(max_heap, -projects[i][1])
            i += 1
        if not max_heap:
            break
        w += -heapq.heappop(max_heap)
        
    print(w)

if __name__ == "__main__":
    solve()

