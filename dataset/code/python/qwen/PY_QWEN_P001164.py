import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    a = input_data[0]
    b = input_data[1]
    
    n = len(a)
    m = len(b)
    
    # Sum of ASCII values
    sum_a = sum(ord(c) for c in a)
    sum_b = sum(ord(c) for c in b)
    
    # LCS with ASCII sum
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if a[i-1] == b[j-1]:
                dp[i][j] = dp[i-1][j-1] + ord(a[i-1])
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                
    lcs_sum = dp[n][m]
    print(sum_a + sum_b - 2 * lcs_sum)

if __name__ == "__main__":
    solve()

