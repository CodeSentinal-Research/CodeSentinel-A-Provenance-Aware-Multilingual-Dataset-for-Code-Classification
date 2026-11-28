from typing import List

def count_edges(m: int) -> int:
    return m

if __name__ == '__main__':
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    print(m)