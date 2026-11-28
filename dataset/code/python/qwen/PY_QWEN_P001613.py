import sys

def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return
    first_line = input_data[0].split()
    n = int(first_line[0])
    m = int(first_line[1])
    k_val = int(first_line[2])
    
    matrix = []
    for i in range(1, n + 1):
        matrix.append(list(map(int, input_data[i].split())))
        
    # Prefix sum matrix
    prefix = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]
            
    result = [[0] * m for _ in range(n)]
    
    for i in range(n):
        for j in range(m):
            r1 = max(0, i - k_val)
            c1 = max(0, j - k_val)
            r2 = min(n - 1, i + k_val)
            c2 = min(m - 1, j + k_val)
            
            # Convert to 1-based for prefix sum
            r1_p, c1_p = r1 + 1, c1 + 1
            r2_p, c2_p = r2 + 1, c2 + 1
            
            s = prefix[r2_p][c2_p] - prefix[r1_p-1][c2_p] - prefix[r2_p][c1_p-1] + prefix[r1_p-1][c1_p-1]
            result[i][j] = s
            
    for row in result:
        print(" ".join(map(str, row)))

solve()

