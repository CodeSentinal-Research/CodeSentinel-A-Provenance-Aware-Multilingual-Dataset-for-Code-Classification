import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    goal = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    # AtMost(goal) - AtMost(goal - 1)
    def at_most(target):
        if target < 0:
            return 0
        left = 0
        count = 0
        current_sum = 0
        for right in range(n):
            current_sum += nums[right]
            while current_sum > target:
                current_sum -= nums[left]
                left += 1
            count += right - left + 1
        return count
        
    print(at_most(goal) - at_most(goal - 1))

solve()

