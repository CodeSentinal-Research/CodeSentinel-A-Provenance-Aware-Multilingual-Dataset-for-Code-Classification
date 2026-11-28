def generate_all_subsequences(nums, index=0, subsequence=[]):
    if index == len(nums):
        print(subsequence)
        return
    generate_all_subsequences(nums, index + 1, subsequence)
    generate_all_subsequences(nums, index + 1, subsequence + [nums[index]])

generate_all_subsequences([1, 2, 3])