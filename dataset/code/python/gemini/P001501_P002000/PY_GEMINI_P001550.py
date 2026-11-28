from typing import List

def sum_abs_diff_window(nums: List[int], k: int) -> List[int]:
    res = []
    for i in range(len(nums) - k + 1):
        window = sorted(nums[i:i + k])
        s = 0
        for j in range(k):
            for m in range(j + 1, k):
                s += abs(window[j] - window[m])
        res.append(s)
    return res

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(*sum_abs_diff_window(nums, k))