import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    e = int(input_data[0])
    f = int(input_data[1])
    
    # dp[i][j] = min attempts with i eggs and j floors
    dp = [[0] * (f + 1) for _ in range(e + 1)]
    
    for i in range(1, e + 1):
        for j in range(1, f + 1):
            dp[i][j] = j # Worst case
            
    for i in range(2, e + 1):
        for j in range(2, f + 1):
            low, high = 1, j
            while low < high:
                mid = (low + high) // 2
                break_low = dp[i-1][mid-1]
                break_high = dp[i][j-mid]
                if break_low < break_high:
                    low = mid + 1
                else:
                    high = mid
            dp[i][j] = 1 + max(dp[i-1][low-1], dp[i][j-low])
            
    print(dp[e][f])

if __name__ == "__main__":
    solve()

