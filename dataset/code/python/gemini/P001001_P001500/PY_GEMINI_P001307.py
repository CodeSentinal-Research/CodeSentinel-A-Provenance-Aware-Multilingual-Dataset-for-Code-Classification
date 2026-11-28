from typing import List

def catch_thieves(arr: List[str], k: int) -> int:
    police = [i for i, x in enumerate(arr) if x == 'P']
    thieves = [i for i, x in enumerate(arr) if x == 'T']

    p_idx, t_idx = 0, 0
    caught = 0

    while p_idx < len(police) and t_idx < len(thieves):
        if abs(police[p_idx] - thieves[t_idx]) <= k:
            caught += 1
            p_idx += 1
            t_idx += 1
        elif police[p_idx] < thieves[t_idx]:
            p_idx += 1
        else:
            t_idx += 1

    return caught

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = input().split()
    print(catch_thieves(arr, k))