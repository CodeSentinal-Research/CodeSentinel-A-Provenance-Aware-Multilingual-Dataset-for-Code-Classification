import sys

def solve():
    expr = sys.stdin.readline().strip()
    n = len(expr)
    
    # dp[i][j][0] = ways to evaluate to False
    # dp[i][j][1] = ways to evaluate to True
    dp = [[[0, 0] for _ in range(n)] for _ in range(n)]
    
    for i in range(0, n, 2):
        if expr[i] == 'T':
            dp[i][i][1] = 1
        else:
            dp[i][i][0] = 1
            
    for length in range(3, n + 1, 2):
        for i in range(0, n - length + 1, 2):
            j = i + length - 1
            for k in range(i + 1, j, 2):
                op = expr[k]
                left_true, left_false = dp[i][k-1][1], dp[i][k-1][0]
                right_true, right_false = dp[k+1][j][1], dp[k+1][j][0]
                
                if op == '&':
                    dp[i][j][1] += left_true * right_true
                    dp[i][j][0] += left_true * right_false + left_false * right_true + left_false * right_false
                elif op == '|':
                    dp[i][j][1] += left_true * right_true + left_true * right_false + left_false * right_true
                    dp[i][j][0] += left_false * right_false
                elif op == '^':
                    dp[i][j][1] += left_true * right_false + left_false * right_true
                    dp[i][j][0] += left_true * right_true + left_false * right_false
                    
    print(dp[0][n-1][1])

if __name__ == "__main__":
    solve()

