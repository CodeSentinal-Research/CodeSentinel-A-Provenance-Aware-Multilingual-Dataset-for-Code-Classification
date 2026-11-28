import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return
    n = int(input_data[0])
    
    grid = []
    row_hashes = []
    for i in range(1, n+1):
        row = list(map(int, input_data[i].split()))
        grid.append(row)
        row_hashes.append(tuple(row))
        
    col_hashes = []
    for j in range(n):
        col = tuple(grid[i][j] for i in range(n))
        col_hashes.append(col)
        
    row_counter = Counter(row_hashes)
    col_counter = Counter(col_hashes)
    
    count = 0
    for rh in row_hashes:
        if rh in col_counter:
            count += col_counter[rh]
            
    print(count)

solve()

