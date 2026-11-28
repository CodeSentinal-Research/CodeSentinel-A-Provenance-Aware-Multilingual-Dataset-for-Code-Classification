from typing import List, Tuple

def count_even_odd(arr: List[int]) -> Tuple[int, int]:
    even_cnt = sum(1 for x in arr if x % 2 == 0)
    odd_cnt = len(arr) - even_cnt
    return even_cnt, odd_cnt

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    even, odd = count_even_odd(arr)
    print(f"Even: {even}, Odd: {odd}")