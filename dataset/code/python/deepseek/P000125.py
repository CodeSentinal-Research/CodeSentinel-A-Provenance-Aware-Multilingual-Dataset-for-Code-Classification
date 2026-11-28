def two_sum(N, target, nums):
    nums_dict = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in nums_dict:
            return [nums_dict[complement], i]
        nums_dict[num] = i
    return None

if __name__ == "__main__":
    N, target = map(int, input().split())
    nums = list(map(int, input().split()))
    result = two_sum(N, target, nums)
    print(" ".join(map(str, result)))