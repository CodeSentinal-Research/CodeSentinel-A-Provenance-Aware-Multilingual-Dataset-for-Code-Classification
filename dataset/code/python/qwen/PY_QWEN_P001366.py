import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    r = int(input_data[idx]); idx += 1
    c = int(input_data[idx]); idx += 1
    
    grid = []
    start = None
    end = None
    empty_count = 0
    
    for i in range(r):
        row = list(map(int, input_data[idx:idx+c]))
        idx += c
        grid.append(row)
        for j in range(c):
            if row[j] == 1:
                start = (i, j)
            elif row[j] == 2:
                end = (i, j)
            elif row[j] == 0:
                empty_count += 1
                
    paths = 0
    
    def backtrack(r_idx, c_idx, visited_count):
        nonlocal paths
        if (r_idx, c_idx) == end:
            if visited_count == empty_count + 1: # +1 for start
                paths += 1
            return
            
        for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
            nr, nc = r_idx + dr, c_idx + dc
            if 0 <= nr < r and 0 <= nc < c and grid[nr][nc] != -1 and (nr, nc) not in visited:
                visited.add((nr, nc))
                backtrack(nr, nc, visited_count + 1)
                visited.remove((nr, nc))
                
    visited = {start}
    backtrack(start[0], start[1], 1)
    print(paths)

if __name__ == "__main__":
    solve()

