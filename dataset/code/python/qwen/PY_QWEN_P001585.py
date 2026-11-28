import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    nums.sort()
    left = 0
    max_freq = 0
    
    for right in range(n):
        k -= nums[right] - nums[right-1] if right > 0 else 0 # This logic is flawed for general case.
        # Correct: cost to make nums[left..right] equal to nums[right] is sum(nums[right] - nums[i])
        # We can maintain sum.
        
    # Re-implementing correctly
    nums.sort()
    left = 0
    current_sum = 0
    max_freq = 0
    
    for right in range(n):
        current_sum += nums[right]
        # Cost to make all elements in window equal to nums[right]
        # Cost = nums[right] * (right - left + 1) - current_sum
        while nums[right] * (right - left + 1) - current_sum > k:
            current_sum -= nums[left]
            left += 1
        max_freq = max(max_freq, right - left + 1)
        
    print(max_freq)

solve()

