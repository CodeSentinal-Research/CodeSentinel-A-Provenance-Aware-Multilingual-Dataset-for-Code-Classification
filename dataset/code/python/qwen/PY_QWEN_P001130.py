import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    grid = []
    for _ in range(n):
        grid.append(input_data[idx]); idx += 1
        
    # Expand grid to 3n x 3n to handle slashes
    size = 3 * n
    expanded = [[0] * size for _ in range(size)]
    
    for r in range(n):
        for c in range(n):
            char = grid[r][c]
            br, bc = 3 * r, 3 * c
            if char == '/':
                expanded[br][bc + 2] = 1
                expanded[br + 1][bc + 1] = 1
                expanded[br + 2][bc] = 1
            elif char == '\\':
                expanded[br][bc] = 1
                expanded[br + 1][bc + 1] = 1
                expanded[br + 2][bc + 2] = 1
                
    # Count regions using BFS/DFS on 0s
    visited = [[False] * size for _ in range(size)]
    regions = 0
    
    def bfs(sr, sc):
        stack = [(sr, sc)]
        visited[sr][sc] = True
        while stack:
            r, c = stack.pop()
            for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < size and 0 <= nc < size and not visited[nr][nc] and expanded[nr][nc] == 0:
                    visited[nr][nc] = True
                    stack.append((nr, nc))
                    
    for r in range(size):
        for c in range(size):
            if expanded[r][c] == 0 and not visited[r][c]:
                bfs(r, c)
                regions += 1
                
    print(regions)

if __name__ == "__main__":
    solve()

