from typing import List

def are_heaps_identical(a: List[int], b: List[int]) -> bool:
    return a == b

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())
    b = list(map(int, input().split()))
    print("YES" if are_heaps_identical(a, b) else "NO")