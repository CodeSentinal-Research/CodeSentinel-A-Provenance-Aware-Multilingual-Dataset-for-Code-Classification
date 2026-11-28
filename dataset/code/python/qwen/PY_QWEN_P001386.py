import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n+1]))
    
    slow = nums[0]
    fast = nums[nums[0]]
    
    while slow != fast:
        slow = nums[slow]
        fast = nums[nums[fast]]
        
    slow = 0
    while slow != fast:
        slow = nums[slow]
        fast = nums[fast]
        
    print(slow)

solve()

