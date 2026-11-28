from typing import List

def count_divisible_in_range(l: int, r: int, k: int) -> int:
    return (r // k) - ((l - 1) // k)

if __name__ == '__main__':
    l, r, k = map(int, input().split())
    print(count_divisible_in_range(l, r, k))