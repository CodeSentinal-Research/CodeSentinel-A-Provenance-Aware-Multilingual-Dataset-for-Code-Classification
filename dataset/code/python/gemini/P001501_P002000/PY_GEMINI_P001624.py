from typing import List

def reconstruct_from_diff(diff: List[int]) -> List[int]:
    res = []
    cur = 0
    for x in diff:
        cur += x
        res.append(cur)
    return res

if __name__ == '__main__':
    n = int(input())
    diff = list(map(int, input().split()))
    print(*reconstruct_from_diff(diff))