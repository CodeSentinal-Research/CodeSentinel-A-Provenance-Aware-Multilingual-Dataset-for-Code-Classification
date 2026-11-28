import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    nums.sort()
    max_sum = 0
    
    for i in range(n // 2):
        max_sum = max(max_sum, nums[i] + nums[n - 1 - i])
        
    print(max_sum)

if __name__ == "__main__":
    solve()

