def max_activities(start_times, end_times):
    sorted_activities = sorted(range(len(start_times)), key=lambda i: end_times[i])

    max_activities = 1

    for i in range(1, len(sorted_activities)):
        if start_times[sorted_activities[i]] >= end_times[sorted_activities[i-1]]:
            max_activities += 1
            end_times[sorted_activities[i]] = start_times[sorted_activities[i]]

    return max_activities


def main():
    N = int(input())

    start_times = []
    end_times = []

    for _ in range(N):
        start, end = map(int, input().split())
        start_times.append(start)
        end_times.append(end)

    max_activities = max_activities(start_times, end_times)

    print(max_activities)


if __name__ == "__main__":
    main()