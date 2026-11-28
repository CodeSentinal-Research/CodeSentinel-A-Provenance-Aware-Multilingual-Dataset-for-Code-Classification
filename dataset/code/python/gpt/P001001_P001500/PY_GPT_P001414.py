# problem title : Count Distinct Absolute Values
# Solve the stated task using standard input and standard output.
from typing import List

def count_distinct_abs(arr: List[int]) -> int:
    return len(set(abs(x) for x in arr))

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(count_distinct_abs(arr))
