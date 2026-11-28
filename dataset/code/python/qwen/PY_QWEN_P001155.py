import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    nums = [1] + nums + [1]
    n_new = len(nums)
    
    dp = [[0] * n_new for _ in range(n_new)]
    
    for length in range(2, n_new):
        for i in range(n_new - length):
            j = i + length
            for k in range(i + 1, j):
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j])
                
    print(dp[0][n_new-1])

if __name__ == "__main__":
    solve()

