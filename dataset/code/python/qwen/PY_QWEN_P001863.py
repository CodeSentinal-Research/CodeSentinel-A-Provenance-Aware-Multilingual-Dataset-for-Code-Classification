import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    keys = list(map(int, input_data[idx:idx+n])); idx += n
    p = list(map(int, input_data[idx:idx+n])); idx += n # successful
    q = list(map(int, input_data[idx:idx+n])) # unsuccessful
    
    # DP for Optimal BST with dummy keys
    # e[i][j] = expected cost for keys i+1..j
    # w[i][j] = sum of probabilities
    
    size = n + 1
    e = [[0]*size for _ in range(size)]
    w = [[0]*size for _ in range(size)]
    
    for i in range(size):
        w[i][i] = q[i]
        e[i][i] = q[i]
        
    for length in range(1, n+1):
        for i in range(n-length+1):
            j = i + length
            w[i][j] = w[i][j-1] + p[j-1] + q[j]
            e[i][j] = float('inf')
            for r in range(i+1, j+1):
                cost = e[i][r-1] + e[r][j] + w[i][j]
                if cost < e[i][j]:
                    e[i][j] = cost
                    
    print(e[0][n])

solve()

