import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    bricks = int(input_data[idx]); idx += 1
    ladders = int(input_data[idx]); idx += 1
    heights = list(map(int, input_data[idx:idx+n]))
    
    ladder_jumps = []
    
    for i in range(n - 1):
        diff = heights[i+1] - heights[i]
        if diff > 0:
            heapq.heappush(ladder_jumps, diff)
            if len(ladder_jumps) > ladders:
                bricks -= heapq.heappop(ladder_jumps)
            if bricks < 0:
                print(i)
                return
                
    print(n - 1)

if __name__ == "__main__":
    solve()

