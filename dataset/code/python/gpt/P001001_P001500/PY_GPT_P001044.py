# problem title : Level of a Heap Node
# Solve the stated task using standard input and standard output.
import math

def node_level(idx: int) -> int:
    return math.floor(math.log2(idx + 1))

if __name__ == '__main__':
    idx = int(input())
    print(node_level(idx))
