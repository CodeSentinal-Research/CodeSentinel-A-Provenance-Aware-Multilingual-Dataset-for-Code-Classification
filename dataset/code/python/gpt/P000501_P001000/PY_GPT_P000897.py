# problem title : LCM of an Array
# Solve the stated task using standard input and standard output.
from typing import List
import math
from functools import reduce

def lcm(a: int, b: int) -> int:
    return (a * b) // math.gcd(a, b)

def array_lcm(arr: List[int]) -> int:
    return reduce(lcm, arr)

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(array_lcm(arr))
