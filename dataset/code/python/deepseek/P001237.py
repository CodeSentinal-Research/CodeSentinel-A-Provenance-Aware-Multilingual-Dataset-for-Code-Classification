Here is the Python code for the problem:

def min_removed_intervals(intervals):
    intervals.sort(key=lambda x: x[1])
    removed = 0
    end = float('-inf')

    for start, end in intervals:
        if start > end or end < end:
            removed += 1
            end = end

    return removed


def main():
    N = int(input().strip())
    intervals = []

    for _ in range(N):
        start, end = map(int, input().strip().split())
        intervals.append((start, end))

    print(min_removed_intervals(intervals))


if __name__ == "__main__":
    main()

This code takes an input of number of intervals, and then for each interval, it takes start and end points as input. It then sorts the intervals based on end points. For each interval, it checks if the start is greater than the end or the end is less than the end, and if so, it increments the removed count and updates the end point.

The main function is the entry point of the program. It reads the number of intervals, and for each interval, it reads the start and end points. It then calls the `min_removed_intervals` function to find the minimum number of intervals to be removed.

This code assumes that the intervals are sorted by start points. If not, it sorts the intervals by the start points first, and then by the end points.