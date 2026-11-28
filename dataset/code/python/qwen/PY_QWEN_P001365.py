import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    r = int(input_data[idx]); idx += 1
    c = int(input_data[idx]); idx += 1
    
    grid = []
    for _ in range(r):
        grid.append(list(map(int, input_data[idx:idx+c])))
        idx += c
        
    max_gold = 0
    
    def backtrack(r_idx, c_idx, current_gold, visited):
        nonlocal max_gold
        max_gold = max(max_gold, current_gold)
        
        for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
            nr, nc = r_idx + dr, c_idx + dc
            if 0 <= nr < r and 0 <= nc < c and grid[nr][nc] > 0 and (nr, nc) not in visited:
                visited.add((nr, nc))
                backtrack(nr, nc, current_gold + grid[nr][nc], visited)
                visited.remove((nr, nc))
                
    for i in range(r):
        for j in range(c):
            if grid[i][j] > 0:
                backtrack(i, j, grid[i][j], {(i, j)})
                
    print(max_gold)

if __name__ == "__main__":
    solve()

