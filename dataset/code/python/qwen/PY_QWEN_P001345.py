import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    total_sum = sum(nums)
    half_sum = total_sum / 2
    min_diff = float('inf')
    
    def backtrack(index, current_sum):
        nonlocal min_diff
        if index == n:
            diff = abs(total_sum - 2 * current_sum)
            min_diff = min(min_diff, diff)
            return
        # Include nums[index]
        backtrack(index + 1, current_sum + nums[index])
        # Exclude nums[index]
        backtrack(index + 1, current_sum)
        
    backtrack(0, 0)
    print(int(min_diff))

if __name__ == "__main__":
    solve()

