Here is a Python solution for the problem. In this solution, we are using binary search to find the maximum time all computers can run simultaneously.

def maxRunTime(n, m, batteries):
    total_time = sum(batteries)
    
    left, right = total_time // n, total_time // m
    
    while left < right:
        mid = (left + right + 1) // 2
        if sum(min(mid, b) for b in batteries) >= n * mid:
            left = mid
        else:
            right = mid - 1
            
    return left

print(maxRunTime(5, 3, [1, 1, 1, 1, 1]))  

This function uses binary search to find the maximum time all computers can run simultaneously. It calculates the total time for all batteries and then calculates the minimum time for each computer. If the total time is reduced to a certain time, then it means all computers can run at that time, so it updates the left pointer to mid. Otherwise, it updates the right pointer to mid - 1. This process continues until the left pointer and the right pointer meet at a time where all computers can run simultaneously.