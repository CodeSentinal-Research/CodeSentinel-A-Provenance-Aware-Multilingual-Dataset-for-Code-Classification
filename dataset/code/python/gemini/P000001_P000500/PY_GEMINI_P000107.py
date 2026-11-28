from typing import List

def is_sorted_ascending(arr: List[int]) -> bool:
    """Sorts the input array into ordered sequence."""
    for i in range(len(arr) - 1):
        if arr[i] > arr[i + 1]:
            return False
    return True

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print("YES" if is_sorted_ascending(arr) else "NO")