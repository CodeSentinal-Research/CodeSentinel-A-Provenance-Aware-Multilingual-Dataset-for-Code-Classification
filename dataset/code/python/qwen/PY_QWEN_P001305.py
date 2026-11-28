import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    freqs = list(map(int, input_data[1:1+n]))
    
    heapq.heapify(freqs)
    total_cost = 0
    
    while len(freqs) > 1:
        f1 = heapq.heappop(freqs)
        f2 = heapq.heappop(freqs)
        cost = f1 + f2
        total_cost += cost
        heapq.heappush(freqs, cost)
        
    print(total_cost)

if __name__ == "__main__":
    solve()

