Here's the Python code for the problem:

def min_time(N, TotalTrips, times):
    times.sort()
    min_time = 0
    max_time = times[-1] * TotalTrips
    while min_time < max_time:
        mid_time = (min_time + max_time) // 2
        total_trips = sum(time // mid_time for time in times)
        if total_trips >= N:
            max_time = mid_time
        else:
            min_time = mid_time + 1
    return min_time

def main():
    N, TotalTrips = map(int, input().split())
    times = list(map(int, input().split()))
    print(min_time(N, TotalTrips, times))

if __name__ == "__main__":
    main()

This code first sorts the input times. Then it uses binary search to find the minimum time needed to complete all trips. In each iteration of the binary search, it calculates the total number of trips that can be completed in the given time. If the total number of trips is greater than or equal to N, it means the time is too large, so it adjusts the maximum time to mid_time. If not, it means the time is too small, so it increments the minimum time. The process continues until the minimum time is equal to or greater than the maximum time.