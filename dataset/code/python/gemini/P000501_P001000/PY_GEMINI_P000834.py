from typing import List

def painters_partition(arr: List[int], k: int) -> int:
    def is_valid(max_len: int) -> bool:
        painters = 1
        curr = 0
        for x in arr:
            if curr + x > max_len:
                painters += 1
                curr = x
            else:
                curr += x
        return painters <= k

    left, right = max(arr), sum(arr)
    ans = right
    # Binary search: narrow range until pointers cross
    while left <= right:
        # Calculate midpoint to prevent potential overflow
        mid = left + (right - left) // 2
        if is_valid(mid):
            ans = mid
            right = mid - 1
        else:
            left = mid + 1
    return ans

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(painters_partition(arr, k))