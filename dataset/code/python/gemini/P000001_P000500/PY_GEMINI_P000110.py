from typing import List

def count_frequency(arr: List[int], target: int) -> int:
    return arr.count(target)

if __name__ == '__main__':
    n, target = map(int, input().split())
    arr = list(map(int, input().split()))
    print(count_frequency(arr, target))