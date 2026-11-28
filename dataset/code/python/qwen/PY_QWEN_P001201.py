import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    grid = []
    for _ in range(n):
        grid.append(list(map(int, input_data[idx:idx+n])))
        idx += n
        
    # dp[i][j] = min sum ending at (i, j) with no two consecutive same columns
    # We can optimize by keeping track of min and second min from previous row
    
    prev_min = [0] * n
    prev_sec_min = [0] * n
    
    # Initialize for row 0
    for j in range(n):
        prev_min[j] = grid[0][j]
        
    for i in range(1, n):
        curr_min = [float('inf')] * n
        # Find min and second min of previous row
        min_val = float('inf')
        sec_min_val = float('inf')
        min_idx = -1
        
        for j in range(n):
            if prev_min[j] < min_val:
                sec_min_val = min_val
                min_val = prev_min[j]
                min_idx = j
            elif prev_min[j] < sec_min_val:
                sec_min_val = prev_min[j]
                
        for j in range(n):
            if j != min_idx:
                curr_min[j] = grid[i][j] + min_val
            else:
                curr_min[j] = grid[i][j] + sec_min_val
                
        prev_min = curr_min
        
    print(min(prev_min))

if __name__ == "__main__":
    solve()

