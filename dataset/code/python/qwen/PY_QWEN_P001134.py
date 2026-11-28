import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    if n == 1:
        print(nums[0])
        return
        
    prev2 = 0
    prev1 = nums[0]
    
    for i in range(1, n):
        curr = max(prev1, prev2 + nums[i])
        prev2 = prev1
        prev1 = curr
        
    print(prev1)

if __name__ == "__main__":
    solve()

