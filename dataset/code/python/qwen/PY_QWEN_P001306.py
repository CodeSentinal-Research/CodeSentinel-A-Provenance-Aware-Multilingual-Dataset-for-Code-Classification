import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    sizes = list(map(int, input_data[1:1+n]))
    
    heapq.heapify(sizes)
    total_cost = 0
    
    while len(sizes) > 1:
        s1 = heapq.heappop(sizes)
        s2 = heapq.heappop(sizes)
        cost = s1 + s2
        total_cost += cost
        heapq.heappush(sizes, cost)
        
    print(total_cost)

if __name__ == "__main__":
    solve()

