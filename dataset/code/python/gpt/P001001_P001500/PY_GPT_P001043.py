# problem title : Find the Last Internal Node
# Solve the stated task using standard input and standard output.
def last_internal_node(n: int) -> int:
    if n <= 1:
        return -1
    return n // 2 - 1

if __name__ == '__main__':
    n = int(input())
    print(last_internal_node(n))
