import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    sticks = list(map(int, input_data[1:1+n]))
    
    heapq.heapify(sticks)
    total_cost = 0
    
    while len(sticks) > 1:
        s1 = heapq.heappop(sticks)
        s2 = heapq.heappop(sticks)
        cost = s1 + s2
        total_cost += cost
        heapq.heappush(sticks, cost)
        
    print(total_cost)

if __name__ == "__main__":
    solve()

