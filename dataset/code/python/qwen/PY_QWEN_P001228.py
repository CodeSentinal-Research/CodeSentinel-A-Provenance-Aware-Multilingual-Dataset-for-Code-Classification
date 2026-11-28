import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    d = int(input_data[0])
    f = int(input_data[1])
    s = int(input_data[2])
    
    dp = [[0] * (s + 1) for _ in range(d + 1)]
    dp[0][0] = 1
    
    for i in range(1, d + 1):
        for j in range(1, s + 1):
            for k in range(1, f + 1):
                if j - k >= 0:
                    dp[i][j] += dp[i-1][j-k]
                    
    print(dp[d][s])

if __name__ == "__main__":
    solve()

