def countSubarrays(nums, K):
    n = len(nums)
    prefix = {0: [0]}
    ans = 0
    xor = 0
    for i in range(n):
        xor ^= nums[i]
        if xor not in prefix:
            prefix[xor] = [i]
        else:
            prefix[xor].append(i)
        for length in range(2, n - i + 1):
            prev_xor = xor ^ K
            if prev_xor in prefix and prefix[prev_xor][0] <= i - length + 1:
                ans += len(prefix[prev_xor])
    return ans