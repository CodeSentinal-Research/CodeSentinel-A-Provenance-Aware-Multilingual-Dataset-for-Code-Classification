from typing import List

def verify_crt(x: int, num: List[int], rem: List[int]) -> bool:
    for n, r in zip(num, rem):
        if x % n != r:
            return False
    return True

if __name__ == '__main__':
    x = int(input())
    k = int(input())
    num = list(map(int, input().split()))
    rem = list(map(int, input().split()))
    print("YES" if verify_crt(x, num, rem) else "NO")