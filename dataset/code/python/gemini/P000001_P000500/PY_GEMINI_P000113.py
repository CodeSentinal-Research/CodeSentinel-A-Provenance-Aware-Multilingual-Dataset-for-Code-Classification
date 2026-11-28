from typing import List

def remove_duplicates(nums: List[int]) -> int:
    if not nums:
        return 0
    k = 1
    for i in range(1, len(nums)):
        if nums[i] != nums[i - 1]:
            nums[k] = nums[i]
            k += 1
    return k

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))
    k = remove_duplicates(nums)
    print(k)
    print(" ".join(map(str, nums[:k])))