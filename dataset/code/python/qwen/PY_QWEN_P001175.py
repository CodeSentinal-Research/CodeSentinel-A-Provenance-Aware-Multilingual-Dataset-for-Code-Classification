import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    matrix = []
    for _ in range(n):
        matrix.append(list(map(int, input_data[idx:idx+n])))
        idx += n
        
    dp = matrix[0][:]
    
    for i in range(1, n):
        new_dp = [0] * n
        for j in range(n):
            min_prev = dp[j]
            if j > 0:
                min_prev = min(min_prev, dp[j-1])
            if j < n - 1:
                min_prev = min(min_prev, dp[j+1])
            new_dp[j] = matrix[i][j] + min_prev
        dp = new_dp
        
    print(min(dp))

if __name__ == "__main__":
    solve()

