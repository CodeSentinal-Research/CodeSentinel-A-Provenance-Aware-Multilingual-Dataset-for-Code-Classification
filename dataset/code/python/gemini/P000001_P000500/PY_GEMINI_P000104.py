from typing import List

def array_average(arr: List[float]) -> float:
    if not arr:
        return 0.0
    return sum(arr) / len(arr)

if __name__ == '__main__':
    n = int(input())
    arr = list(map(float, input().split()))
    print(f"{array_average(arr):.2f}")