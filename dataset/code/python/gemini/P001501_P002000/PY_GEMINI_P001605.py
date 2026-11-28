from typing import List

def max_subarray_len_sum_k(nums: List[int], k: int) -> int:
    seen = {0: -1}
    cur_sum = max_len = 0

    for i, x in enumerate(nums):
        cur_sum += x
        if cur_sum - k in seen:
            max_len = max(max_len, i - seen[cur_sum - k])
        if cur_sum not in seen:
            seen[cur_sum] = i

    return max_len

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(max_subarray_len_sum_k(nums, k))