def minSubarray(nums, p):
    length = len(nums)
    prefix_sum = [0] * (length + 1)
    for i in range(length):
        prefix_sum[i + 1] = prefix_sum[i] + nums[i]

    min_len = float('inf')
    if prefix_sum[-1] % p == 0:
        min_len = 0
    else:
        for i in range(length):
            remainder = prefix_sum[i + 1] % p
            if remainder == 0 or remainder == p or remainder == 0:
                min_len = min(min_len, abs(remainder - p))

    if min_len == float('inf'):
        return -1
    else:
        return min_len


def main():
    nums = [1, 2, -3, 4, -2]
    p = 2
    print(minSubarray(nums, p))


if __name__ == "__main__":
    main()