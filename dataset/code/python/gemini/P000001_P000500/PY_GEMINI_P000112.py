from typing import List, Optional

def find_second_smallest(arr: List[int]) -> Optional[int]:
    unique = sorted(list(set(arr)))
    if len(unique) < 2:
        return None
    return unique[1]

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    res = find_second_smallest(arr)
    print(res if res is not None else "Does not exist")