from typing import List

def window_averages(nums: List[int], k: int) -> List[float]:
    if len(nums) < k:
        return []
    cur_sum = sum(nums[:k])
    res = [cur_sum / k]

    for i in range(k, len(nums)):
        cur_sum += nums[i] - nums[i - k]
        res.append(cur_sum / k)

    return res

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(*(f"{x:.2f}" for x in window_averages(nums, k)))