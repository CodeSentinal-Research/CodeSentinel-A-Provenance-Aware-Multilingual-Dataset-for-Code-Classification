import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    if n == 0:
        print(0)
        return
        
    # Distinct palindromic subsequences is complex.
    # Simplified for standard CP: Count distinct palindromic substrings? No, subsequences.
    # This is a hard problem. Using standard DP for distinct palindromic subsequences.
    
    MOD = 10**9 + 7
    dp = [[0] * n for _ in range(n)]
    last = {}
    
    for i in range(n):
        dp[i][i] = 1
        
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            if s[i] == s[j]:
                dp[i][j] = dp[i+1][j-1] * 2 + 2
                # Subtract duplicates if same char exists inside
                left = i + 1
                right = j - 1
                while left <= right and s[left] != s[i]:
                    left += 1
                while left <= right and s[right] != s[j]:
                    right -= 1
                if left > right:
                    pass
                elif left == right:
                    dp[i][j] -= 1
                else:
                    dp[i][j] -= dp[left+1][right-1] + 2
            else:
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]
                
    print(dp[0][n-1])

if __name__ == "__main__":
    solve()

