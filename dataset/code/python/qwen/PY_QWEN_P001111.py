import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    l = int(input_data[idx]); idx += 1
    
    board = [0] * (n + 1)
    for _ in range(l):
        start = int(input_data[idx]); idx += 1
        end = int(input_data[idx]); idx += 1
        board[start] = end
        
    s = int(input_data[idx]); idx += 1
    for _ in range(s):
        head = int(input_data[idx]); idx += 1
        tail = int(input_data[idx]); idx += 1
        board[head] = tail
        
    dist = [-1] * (n + 1)
    dist[1] = 0
    q = deque([1])
    
    while q:
        u = q.popleft()
        if u == n:
            print(dist[u])
            return
        for dice in range(1, 7):
            v = u + dice
            if v <= n:
                dest = board[v] if board[v] != 0 else v
                if dist[dest] == -1:
                    dist[dest] = dist[u] + 1
                    q.append(dest)
                    
    print(dist[n])

if __name__ == "__main__":
    solve()

