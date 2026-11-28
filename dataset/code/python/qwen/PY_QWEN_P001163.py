import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    a = input_data[0]
    b = input_data[1]
    c = input_data[2]
    
    if len(a) + len(b) != len(c):
        print("NO")
        return
        
    n = len(a)
    m = len(b)
    
    dp = [[False] * (m + 1) for _ in range(n + 1)]
    dp[0][0] = True
    
    for i in range(n + 1):
        for j in range(m + 1):
            if i > 0 and a[i-1] == c[i+j-1]:
                dp[i][j] = dp[i][j] or dp[i-1][j]
            if j > 0 and b[j-1] == c[i+j-1]:
                dp[i][j] = dp[i][j] or dp[i][j-1]
                
    print("YES" if dp[n][m] else "NO")

if __name__ == "__main__":
    solve()

