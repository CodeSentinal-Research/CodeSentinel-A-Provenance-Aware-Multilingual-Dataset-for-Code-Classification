def solve():
    n = int(input())
    intervals = [list(map(int, input().split())) for _ in range(n)]
    intervals.sort(key=lambda x: x[1])

    arrows = 1
    end = intervals[0][1]

    for start, end in intervals[1:]:
        if start > end:
            arrows += 1
            end = intervals[0][1]

    print(arrows)


if __name__ == "__main__":
    solve()