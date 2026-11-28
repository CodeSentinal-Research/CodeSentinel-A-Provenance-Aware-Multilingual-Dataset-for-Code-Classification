import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    boxes = list(map(int, input_data[1:1+n]))
    
    # Compress boxes into groups: (color, count)
    groups = []
    for b in boxes:
        if groups and groups[-1][0] == b:
            groups[-1] = (b, groups[-1][1] + 1)
        else:
            groups.append((b, 1))
            
    m = len(groups)
    
    # dp[i][j][k] = max points for groups[i..j] with k additional boxes of color groups[j][0] attached to the right
    dp = [[[0] * (n + 1) for _ in range(m)] for _ in range(m)]
    
    def solve_dp(i, j, k):
        if i > j:
            return 0
        if dp[i][j][k] != 0:
            return dp[i][j][k]
            
        # Remove group j immediately
        res = solve_dp(i, j - 1, 0) + (groups[j][1] + k) ** 2
        
        # Try to merge group j with some previous group p having same color
        for p in range(i, j):
            if groups[p][0] == groups[j][0]:
                res = max(res, solve_dp(i, p, groups[j][1] + k) + solve_dp(p + 1, j - 1, 0))
                
        dp[i][j][k] = res
        return res
        
    print(solve_dp(0, m - 1, 0))

if __name__ == "__main__":
    solve()

