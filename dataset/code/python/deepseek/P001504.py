def longestNiceSubarray():
    n = int(input())
    nums = list(map(int, input().split()))

    res = 0
    count = [0] * (1 << n)
    count[0] = 1

    for i in range(n):
        for j in range(i):
            if (nums[i] & nums[j]) == 0 and (count[nums[i] | nums[j]] & nums[j]) == 0:
                count[nums[i] | nums[j]] += count[nums[i]]
                res = max(res, count[nums[i] | nums[j]])

    return res

if __name__ == "__main__":
    print(longestNiceSubarray())