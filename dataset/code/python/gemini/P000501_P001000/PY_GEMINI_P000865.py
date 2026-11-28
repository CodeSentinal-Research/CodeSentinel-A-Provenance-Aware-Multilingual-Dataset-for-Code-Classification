from typing import List

def xor_all(arr: List[int]) -> int:
    ans = 0
    for x in arr:
        ans ^= x
    return ans

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(xor_all(arr))