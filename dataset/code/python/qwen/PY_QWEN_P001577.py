import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    count = 0
    is_increasing = True
    for i in range(1, k):
        if nums[i] <= nums[i-1]:
            is_increasing = False
            break
    if is_increasing:
        count += 1
        
    for i in range(k, n):
        # Check if new window is increasing
        # We can't easily update "is_increasing" with just one check if the break was in the middle.
        # So we re-check or use a counter of violations.
        pass
        
    # Simpler O(N*K) might TLE. Let's use violation count.
    violations = 0
    for i in range(1, k):
        if nums[i] <= nums[i-1]:
            violations += 1
    if violations == 0:
        count += 1
        
    for i in range(k, n):
        # Remove effect of nums[i-k]
        if i - k + 1 > 0: # Check pair (i-k, i-k+1)
             if nums[i-k+1] <= nums[i-k]:
                 violations -= 1
        # Add effect of nums[i]
        if nums[i] <= nums[i-1]:
            violations += 1
            
        if violations == 0:
            count += 1
            
    print(count)

solve()

