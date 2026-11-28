import sys
from collections import defaultdict, deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    graph = defaultdict(list)
    for _ in range(n):
        src = input_data[idx]; idx += 1
        dst = input_data[idx]; idx += 1
        graph[src].append(dst)
        
    # Sort destinations lexicographically for each source
    for key in graph:
        graph[key].sort(reverse=True) # Use pop() from end for efficiency
        
    itinerary = []
    stack = ["JFK"]
    
    while stack:
        while graph[stack[-1]]:
            next_dest = graph[stack[-1]].pop()
            stack.append(next_dest)
        itinerary.append(stack.pop())
        
    print(" ".join(itinerary[::-1]))

if __name__ == "__main__":
    solve()

