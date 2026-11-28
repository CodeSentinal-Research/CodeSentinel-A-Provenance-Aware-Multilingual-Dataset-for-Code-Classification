def longestSubarray():
    N, K = map(int, input().split())
    nums = list(map(int, input().split()))

    left, right = 0, 0
    distinct_count = 0
    counts = {}

    longest = 0

    while right < N:
        if nums[right] in counts:
            counts[nums[right]] += 1
        else:
            counts[nums[right]] = 1

        if counts[nums[right]] == 1:
            distinct_count += 1

        while distinct_count > K:
            counts[nums[left]] -= 1
            if counts[nums[left]] == 0:
                distinct_count -= 1

            left += 1

        longest = max(longest, right - left + 1)

        right += 1

    print(longest)


longestSubarray()