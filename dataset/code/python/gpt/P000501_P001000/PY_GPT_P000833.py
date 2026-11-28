# problem title : Allocate Minimum Number of Pages
# Solve the stated task using standard input and standard output.
from typing import List

def find_pages(arr: List[int], k: int) -> int:
    if k > len(arr):
        return -1
    def is_possible(max_pages: int) -> bool:
        students = 1
        pages = 0
        for x in arr:
            if pages + x > max_pages:
                students += 1
                pages = x
            else:
                pages += x
        return students <= k

    left, right = max(arr), sum(arr)
    ans = -1
    while left <= right:
        mid = left + (right - left) // 2
        if is_possible(mid):
            ans = mid
            right = mid - 1
        else:
            left = mid + 1
    return ans

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(find_pages(arr, k))
