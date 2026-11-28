def minTaps(N, ranges):
    intervals = [0] * (N + 1)

    for i, range in enumerate(ranges):
        start, end = max(0, i - range), min(N, i + range)
        for j in range(start, end):
            intervals[j] += 1

    tap_count = 0
    current_interval = 0

    for interval in intervals:
        if interval > 0:
            tap_count += 1
            current_interval += interval

    if current_interval < N:
        return -1
    else:
        return tap_count

N = int(input().strip())
ranges = list(map(int, input().strip().split()))

print(minTaps(N, ranges))