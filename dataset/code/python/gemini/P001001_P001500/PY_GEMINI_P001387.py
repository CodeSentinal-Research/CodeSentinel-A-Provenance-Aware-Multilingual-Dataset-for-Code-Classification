from typing import List
from collections import Counter

def check_equality(a: List[int], b: List[int]) -> bool:
    return Counter(a) == Counter(b)

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    print(1 if check_equality(a, b) else 0)