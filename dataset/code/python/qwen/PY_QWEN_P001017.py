import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    ropes = list(map(int, input_data[1:1+n]))
    
    heapq.heapify(ropes)
    total_cost = 0
    
    while len(ropes) > 1:
        r1 = heapq.heappop(ropes)
        r2 = heapq.heappop(ropes)
        cost = r1 + r2
        total_cost += cost
        heapq.heappush(ropes, cost)
        
    print(total_cost)

if __name__ == "__main__":
    solve()

