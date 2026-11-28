from typing import List

def merge_without_extra_space(a: List[int], b: List[int]) -> None:
    i = len(a) - 1
    j = 0
    while i >= 0 and j < len(b):
        if a[i] > b[j]:
            a[i], b[j] = b[j], a[i]
            i -= 1
            j += 1
        else:
            break
    a.sort()
    b.sort()

if __name__ == '__main__':
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    merge_without_extra_space(a, b)
    print(*(a + b))