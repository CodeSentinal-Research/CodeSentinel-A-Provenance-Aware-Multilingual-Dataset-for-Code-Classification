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
    if n == 2:
        print(max(nums[0], nums[1]))
        return
        
    def rob_linear(arr):
        prev2 = 0
        prev1 = arr[0]
        for i in range(1, len(arr)):
            curr = max(prev1, prev2 + arr[i])
            prev2 = prev1
            prev1 = curr
        return prev1
        
    print(max(rob_linear(nums[:-1]), rob_linear(nums[1:])))

if __name__ == "__main__":
    solve()

