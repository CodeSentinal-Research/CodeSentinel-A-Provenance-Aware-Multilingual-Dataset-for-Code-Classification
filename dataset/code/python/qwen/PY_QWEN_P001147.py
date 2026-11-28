import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    s1 = input_data[0]
    s2 = input_data[1]
    
    n = len(s1)
    m = len(s2)
    
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    max_len = 0
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
                max_len = max(max_len, dp[i][j])
            else:
                dp[i][j] = 0
                
    print(max_len)

if __name__ == "__main__":
    solve()

