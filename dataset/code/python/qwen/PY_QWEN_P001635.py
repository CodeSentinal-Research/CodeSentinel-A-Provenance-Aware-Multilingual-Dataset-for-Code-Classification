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
        
    # Transform 0 to -1
    trans = [[1 if matrix[i][j] == 1 else -1 for j in range(m)] for i in range(n)]
    
    count = 0
    
    for r1 in range(n):
        col_sums = [0] * m
        for r2 in range(r1, n):
            for c in range(m):
                col_sums[c] += trans[r2][c]
                
            prefix_s = [0] * (m + 1)
            for j in range(m):
                prefix_s[j+1] = prefix_s[j] + col_sums[j]
                
            from collections import Counter
            counter = Counter()
            counter[0] = 1
            for s in prefix_s[1:]:
                if s in counter:
                    count += counter[s]
                counter[s] += 1
                
    print(count)

solve()

