from typing import List

def max_len_zero_sum(arr: List[int]) -> int:
    seen = {0: -1}
    prefix = 0
    max_len = 0
    for i, x in enumerate(arr):
        prefix += x
        if prefix in seen:
            max_len = max(max_len, i - seen[prefix])
        else:
            seen[prefix] = i
    return max_len

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(max_len_zero_sum(arr))