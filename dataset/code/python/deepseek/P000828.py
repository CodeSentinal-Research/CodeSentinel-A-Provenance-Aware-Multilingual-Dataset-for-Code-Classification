def findRightInterval(intervals):
    endpoints_and_indices = {interval[1]: i for i, interval in enumerate(intervals)}

    intervals.sort(key=lambda x: x[0])

    right_intervals = [-1] * len(intervals)

    for i, interval in enumerate(intervals):
        smallest_end = interval[1] + 1
        for j in range(i + 1, len(intervals)):
            if intervals[j][0] >= smallest_end:
                smallest_end = intervals[j][0]
                right_intervals[endpoints_and_indices[interval[1]]] = endpoints_and_indices[smallest_end]
                break

    return right_intervals

def main():
    n = int(input())
    intervals = [list(map(int, input().split())) for _ in range(n)]
    print(findRightInterval(intervals))

if __name__ == "__main__":
    main()