import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    maze = []
    for _ in range(n):
        maze.append(list(map(int, input_data[idx:idx+n])))
        idx += n
        
    paths = []
    
    def backtrack(r, c, path):
        if r == n - 1 and c == n - 1:
            paths.append(path)
            return
        if r < 0 or r >= n or c < 0 or c >= n or maze[r][c] == 0:
            return
            
        maze[r][c] = 0 # Mark visited
        # Down
        backtrack(r + 1, c, path + "D")
        # Up
        backtrack(r - 1, c, path + "U")
        # Right
        backtrack(r, c + 1, path + "R")
        # Left
        backtrack(r, c - 1, path + "L")
        maze[r][c] = 1 # Unmark
        
    backtrack(0, 0, "")
    paths.sort()
    for p in paths:
        print(p)

if __name__ == "__main__":
    solve()

