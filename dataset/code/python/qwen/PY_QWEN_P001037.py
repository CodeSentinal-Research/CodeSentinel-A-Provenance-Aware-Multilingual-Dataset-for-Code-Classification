import sys
from collections import Counter
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    tasks = list(input_data[1])
    k = int(input_data[2])
    
    counter = Counter(tasks)
    max_heap = [-freq for freq in counter.values()]
    heapq.heapify(max_heap)
    
    time = 0
    while max_heap:
        temp = []
        cycle = k + 1
        while cycle > 0 and max_heap:
            freq = heapq.heappop(max_heap)
            if freq < -1:
                temp.append(freq + 1)
            cycle -= 1
            time += 1
            
        for f in temp:
            heapq.heappush(max_heap, f)
            
        if max_heap:
            time += cycle # Idle time
            
    print(time)

if __name__ == "__main__":
    solve()

