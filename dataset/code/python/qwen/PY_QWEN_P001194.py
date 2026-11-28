import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    arr = list(map(int, input_data[idx:idx+n]))
    
    dp = [0] * (n + 1)
    
    for i in range(1, n + 1):
        max_val = -float('inf')
        for j in range(1, min(i, k) + 1):
            max_val = max(max_val, arr[i-j])
            dp[i] = max(dp[i], dp[i-j] + max_val * j)
            
    print(dp[n])

if __name__ == "__main__":
    solve()

