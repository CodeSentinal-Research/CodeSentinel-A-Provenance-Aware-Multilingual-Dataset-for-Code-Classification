def can_partition(nums, k):
    total_sum = sum(nums)
    
    if total_sum % k != 0:
        return "NO"
    
    target_sum = total_sum // k
    
    count = [0] * (target_sum + 1)
    count[0] = 1

    for num in nums:
        for i in range(target_sum, num - 1, -1):
            count[i] += count[i - num]

    for i in range(target_sum, -1, -1):
        if count[i] == k:
            return "YES"

    return "NO"


n, k = map(int, input().split())
nums = list(map(int, input().split()))

print(can_partition(nums, k))