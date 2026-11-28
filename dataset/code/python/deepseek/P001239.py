def insertInterval(intervals, newInterval):
    i, result = 0, []
    while i < len(intervals) and intervals[i][1] < newInterval[0]:
        result.append(intervals[i])
        i += 1
    while intervals[i][0] < newInterval[1] and i < len(intervals):
        newInterval = [min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])]
        i += 1
    result.append(newInterval)
    while i < len(intervals):
        result.append(intervals[i])
        i += 1
    return result

def main():
    N = int(input().strip())
    intervals = []
    for _ in range(N):
        start, end = map(int, input().strip().split())
        intervals.append([start, end])
    new_start, new_end = map(int, input().strip().split())
    newInterval = [new_start, new_end]
    result = insertInterval(intervals, newInterval)
    for start, end in result:
        print("[{},{}]".format(start, end))

if __name__ == "__main__":
    main()