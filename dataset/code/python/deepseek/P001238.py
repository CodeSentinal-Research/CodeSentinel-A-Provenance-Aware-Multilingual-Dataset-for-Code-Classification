Here is the Python code for the problem. 

def merge_intervals(intervals):
    intervals.sort(key=lambda x: x[0])

    merged = []

    for interval in intervals:
        if not merged or merged[-1][1] < interval[0]:
            merged.append(interval)
        else:
            merged[-1][1] = max(merged[-1][1], interval[1])

    return merged

def main():
    n = int(input().strip())

    intervals = []

    for _ in range(n):
        start, end = map(int, input().strip().split())
        intervals.append((start, end))

    merged = merge_intervals(intervals)

    for start, end in merged:
        print(start, end)

if __name__ == "__main__":
    main()

The `merge_intervals` function sorts the input intervals and merges them. It uses a list `merged` to store the merged intervals. The function iterates over the sorted list of intervals, and for each interval, it checks if the last interval in `merged` is less than the start of the current interval. If it is, the current interval is added to `merged`. If not, the end of the last interval in `merged` is updated to the maximum of the last interval's end and the current interval's end. Finally, the merged intervals are printed out.

The `main` function reads the number of intervals, then reads the intervals in a loop. It calls `merge_intervals` to merge the intervals, and then prints out the merged intervals.