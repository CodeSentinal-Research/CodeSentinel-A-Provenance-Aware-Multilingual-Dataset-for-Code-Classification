import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    total = sum(nums)
    if total % 2 != 0:
        print("NO")
        return
        
    target = total // 2
    dp = [False] * (target + 1)
    dp[0] = True
    
    for num in nums:
        for j in range(target, num - 1, -1):
            if dp[j - num]:
                dp[j] = True
                
    print("YES" if dp[target] else "NO")

if __name__ == "__main__":
    solve()

