from typing import List

def is_max_heap(arr: List[int]) -> bool:
    n = len(arr)
    for i in range((n - 2) // 2 + 1):
        left = 2 * i + 1
        right = 2 * i + 2
        if left < n and arr[i] < arr[left]:
            return False
        if right < n and arr[i] < arr[right]:
            return False
    return True

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print("YES" if is_max_heap(arr) else "NO")