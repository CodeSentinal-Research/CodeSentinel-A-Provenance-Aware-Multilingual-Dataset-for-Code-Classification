from typing import List

def aggressive_cows(stalls: List[int], k: int) -> int:
    stalls.sort()
    def can_place(min_dist: int) -> bool:
        cows = 1
        last = stalls[0]
        for i in range(1, len(stalls)):
            if stalls[i] - last >= min_dist:
                cows += 1
                last = stalls[i]
                if cows == k:
                    return True
        return False

    left, right = 1, stalls[-1] - stalls[0]
    ans = 1
    # Binary search: narrow range until pointers cross
    while left <= right:
        # Calculate midpoint to prevent potential overflow
        mid = left + (right - left) // 2
        if can_place(mid):
            ans = mid
            left = mid + 1
        else:
            right = mid - 1
    return ans

if __name__ == '__main__':
    n, k = map(int, input().split())
    stalls = list(map(int, input().split()))
    print(aggressive_cows(stalls, k))