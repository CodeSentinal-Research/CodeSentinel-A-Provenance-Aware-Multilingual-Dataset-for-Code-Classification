import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    s = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    dp = [False] * (s + 1)
    dp[0] = True
    
    for num in nums:
        for j in range(s, num - 1, -1):
            if dp[j - num]:
                dp[j] = True
                
    print("YES" if dp[s] else "NO")

if __name__ == "__main__":
    solve()

