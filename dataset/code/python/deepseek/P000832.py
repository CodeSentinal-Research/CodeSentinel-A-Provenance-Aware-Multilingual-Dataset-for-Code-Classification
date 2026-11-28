def splitArray(nums, k):
    def check(mid):
        cnt = 0
        total = 0
        for num in nums:
            if total + num > mid:
                cnt += 1
                total = num
            else:
                total += num
        if total > 0:
            cnt += 1
        return cnt <= k

    l, r = max(nums), sum(nums)
    while l < r:
        mid = (l + r) // 2
        if check(mid):
            r = mid
        else:
            l = mid + 1
    return l

nums = [1, 2, 3, 4, 5]
k = 2
print(splitArray(nums, k))