def maxSubArrayLen(nums, k):
    if not nums:
        return 0

    num_dict = {0: -1}
    sum_ = 0
    max_length = 0
    for i in range(len(nums)):
        sum_ += nums[i]
        if sum_ not in num_dict:
            num_dict[sum_] = i
        if sum_ - k in num_dict:
            max_length = max(max_length, i - num_dict[sum_ - k])

    return max_length