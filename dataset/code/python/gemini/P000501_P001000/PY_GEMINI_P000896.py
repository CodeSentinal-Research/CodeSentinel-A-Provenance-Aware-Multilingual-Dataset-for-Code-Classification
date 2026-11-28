from typing import List
import math
from functools import reduce

def array_gcd(arr: List[int]) -> int:
    """Computes the Greatest Common Divisor (GCD) using Euclidean algorithm."""
    return reduce(math.gcd, arr)

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(array_gcd(arr))