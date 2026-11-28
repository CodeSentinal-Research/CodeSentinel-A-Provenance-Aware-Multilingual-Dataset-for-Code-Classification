Here is the Python code with no explanations and no markdown.

def min_removal(N, intervals):
    intervals.sort(key=lambda x: x[1])

    end = intervals[0][1]
    count = 1

    for start, end in intervals[1:]:
        if start > end:
            count += 1
            end = intervals[0][1]
        elif end > intervals[0][1]:
            end = intervals[0][1]

    return count

def main():
    N = int(input().strip())
    intervals = [list(map(int, input().strip().split())) for _ in range(N)]
    print(min_removal(N, intervals))

if __name__ == '__main__':
    main()

This code sorts the intervals by their endpoints. It then iterates through the sorted intervals, checking for overlaps. If a current interval starts after the end of the previous one, it increments the count and updates the end of the current interval. If a current interval ends after the end of the previous one, it updates the end of the current interval. The function finally returns the count of removed intervals.