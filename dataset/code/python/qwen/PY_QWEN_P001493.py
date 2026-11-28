import sys

def solve():
    s = sys.stdin.readline().strip()
    c = sys.stdin.readline().strip()
    n = len(s)
    
    distances = [float('inf')] * n
    
    # Left to right
    prev_c = -float('inf')
    for i in range(n):
        if s[i] == c:
            prev_c = i
        distances[i] = min(distances[i], i - prev_c)
        
    # Right to left
    next_c = float('inf')
    for i in range(n - 1, -1, -1):
        if s[i] == c:
            next_c = i
        distances[i] = min(distances[i], next_c - i)
        
    print(*distances)

solve()

