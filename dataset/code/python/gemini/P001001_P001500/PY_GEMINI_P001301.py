from typing import List

def max_meetings(start: List[int], end: List[int]) -> int:
    meetings = sorted(zip(end, start))
    count = 0
    last_end = -1

    for e, s in meetings:
        if s > last_end:
            count += 1
            last_end = e

    return count

if __name__ == '__main__':
    n = int(input())
    start = list(map(int, input().split()))
    end = list(map(int, input().split()))
    print(max_meetings(start, end))