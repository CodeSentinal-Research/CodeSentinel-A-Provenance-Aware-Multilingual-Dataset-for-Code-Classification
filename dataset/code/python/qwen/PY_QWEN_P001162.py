import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    text = input_data[0]
    pattern = input_data[1]
    
    n = len(text)
    m = len(pattern)
    
    dp = [[False] * (m + 1) for _ in range(n + 1)]
    dp[0][0] = True
    
    for j in range(2, m + 1):
        if pattern[j-1] == '*':
            dp[0][j] = dp[0][j-2]
            
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if pattern[j-1] == '*':
                dp[i][j] = dp[i][j-2]
                if pattern[j-2] == '.' or pattern[j-2] == text[i-1]:
                    dp[i][j] = dp[i][j] or dp[i-1][j]
            elif pattern[j-1] == '.' or pattern[j-1] == text[i-1]:
                dp[i][j] = dp[i-1][j-1]
                
    print("YES" if dp[n][m] else "NO")

if __name__ == "__main__":
    solve()

