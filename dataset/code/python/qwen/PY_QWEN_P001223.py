import sys

def solve():
    n = int(sys.stdin.readline())
    
    if n == 0:
        print(1)
        return
        
    # dp[i][0] = ends with 0, dp[i][1] = ends with 1
    end_with_0 = 1
    end_with_1 = 1
    
    for _ in range(2, n + 1):
        new_0 = end_with_0 + end_with_1
        new_1 = end_with_0
        end_with_0 = new_0
        end_with_1 = new_1
        
    print(end_with_0 + end_with_1)

if __name__ == "__main__":
    solve()

