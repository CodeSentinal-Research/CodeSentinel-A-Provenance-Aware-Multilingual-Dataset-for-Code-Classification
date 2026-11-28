from typing import List

def longest_even_odd_subarray(arr: List[int]) -> int:
    diff_map = {0: -1}
    diff = 0
    max_len = 0

    for i, x in enumerate(arr):
        diff += 1 if x % 2 == 0 else -1
        if diff in diff_map:
            max_len = max(max_len, i - diff_map[diff])
        else:
            diff_map[diff] = i

    return max_len

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(longest_even_odd_subarray(arr))