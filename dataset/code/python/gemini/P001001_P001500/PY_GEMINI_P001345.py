from typing import List

def tug_of_war(arr: List[int]) -> int:
    n = len(arr)
    total_sum = sum(arr)
    half_size = n // 2
    min_diff = float('inf')

    def backtrack(idx: int, count: int, cur_sum: int):
        nonlocal min_diff
        if count == half_size:
            diff = abs(total_sum - 2 * cur_sum)
            min_diff = min(min_diff, diff)
            return
        if idx == n:
            return

        # Include arr[idx]
        backtrack(idx + 1, count + 1, cur_sum + arr[idx])
        # Exclude arr[idx]
        backtrack(idx + 1, count, cur_sum)

    backtrack(0, 0, 0)
    return min_diff

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(tug_of_war(arr))