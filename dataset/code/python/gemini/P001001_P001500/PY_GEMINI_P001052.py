from typing import List

def heap_level_order(arr: List[int]) -> List[int]:
    return arr

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(" ".join(map(str, arr)))