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
        
    prefix = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]
            
    q = int(input_data[n + 1])
    output = []
    for i in range(n + 2, n + 2 + q):
        parts = input_data[i].split()
        r1 = int(parts[0])
        c1 = int(parts[1])
        r2 = int(parts[2])
        c2 = int(parts[3])
        
        # Convert to 1-based if 0-based input
        # Assuming 0-based input based on standard competitive programming
        r1_p, c1_p = r1 + 1, c1 + 1
        r2_p, c2_p = r2 + 1, c2 + 1
        
        s = prefix[r2_p][c2_p] - prefix[r1_p-1][c2_p] - prefix[r2_p][c1_p-1] + prefix[r1_p-1][c1_p-1]
        output.append(str(s))
        
    print("\n".join(output))

solve()

