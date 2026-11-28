from typing import List

def vacation_planning(n: int, activities: List[List[int]]) -> int:
    a, b, c = activities[0][0], activities[0][1], activities[0][2]

    for i in range(1, n):
        na = activities[i][0] + max(b, c)
        nb = activities[i][1] + max(a, c)
        nc = activities[i][2] + max(a, b)
        a, b, c = na, nb, nc

    return max(a, b, c)

if __name__ == '__main__':
    n = int(input())
    activities = [list(map(int, input().split())) for _ in range(n)]
    print(vacation_planning(n, activities))