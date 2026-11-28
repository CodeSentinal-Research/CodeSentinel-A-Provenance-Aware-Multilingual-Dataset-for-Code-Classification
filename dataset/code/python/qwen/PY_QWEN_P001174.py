import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    triangle = []
    for i in range(n):
        triangle.append(list(map(int, input_data[idx:idx+i+1])))
        idx += i + 1
        
    dp = triangle[-1][:]
    
    for i in range(n - 2, -1, -1):
        for j in range(i + 1):
            dp[j] = triangle[i][j] + min(dp[j], dp[j+1])
            
    print(dp[0])

if __name__ == "__main__":
    solve()

