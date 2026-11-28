import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        idx = 1
        rooms = []
        for _ in range(n):
            k = int(tokens[idx])
            rooms.append(list(map(int, tokens[idx+1:idx+1+k])))
            idx += 1 + k
        visited = {0}
        q = deque([0])
        while q:
            room = q.popleft()
            for key in rooms[room]:
                if key not in visited:
                    visited.add(key)
                    q.append(key)
        print("true" if len(visited) == n else "false")
if __name__ == '__main__':
    main()