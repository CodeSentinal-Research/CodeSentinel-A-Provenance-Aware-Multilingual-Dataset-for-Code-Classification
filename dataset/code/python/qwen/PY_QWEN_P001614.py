import sys

def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return
    first_line = input_data[0].split()
    n = int(first_line[0])
    m = int(first_line[1])
    
    matrix = []
    for i in range(1, n + 1):
        matrix.append(list(map(int, input_data[i].split())))
        
    # Prefix sum
    prefix = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]
            
    max_sum = float('-inf')
    
    for r1 in range(1, n + 1):
        for r2 in range(r1, n + 1):
            # Compress rows r1 to r2 into a 1D array of column sums
            col_sums = []
            for c in range(1, m + 1):
                s = prefix[r2][c] - prefix[r1-1][c] - prefix[r2][c-1] + prefix[r1-1][c-1]
                col_sums.append(s)
                
            # Kadane's algorithm on col_sums
            current_max = col_sums[0]
            global_max = col_sums[0]
            for k in range(1, m):
                current_max = max(col_sums[k], current_max + col_sums[k])
                global_max = max(global_max, current_max)
                
            max_sum = max(max_sum, global_max)
            
    print(max_sum)

solve()

