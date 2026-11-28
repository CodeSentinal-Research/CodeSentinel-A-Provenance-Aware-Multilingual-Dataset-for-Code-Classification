def count_internal_nodes(n: int) -> int:
    return n // 2

if __name__ == '__main__':
    n = int(input())
    print(count_internal_nodes(n))