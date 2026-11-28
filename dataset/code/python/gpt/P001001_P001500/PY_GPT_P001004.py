# problem title : Heap Height Calculation
# Solve the stated task using standard input and standard output.
import math

def heap_height(n: int) -> int:
    if n <= 0:
        return 0
    return math.floor(math.log2(n))

if __name__ == '__main__':
    n = int(input())
    print(heap_height(n))
