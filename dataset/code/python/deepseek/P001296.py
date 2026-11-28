Here is the Python code for the problem:

def earliest_full_bloom(N, planting_times, growing_times):
    planting_times.sort()
    growing_times.sort()
    earliest_bloom = float('inf')
    for i in range(N):
        earliest_bloom = min(earliest_bloom, planting_times[i] + growing_times[i])
    return earliest_bloom

def main():
    N = int(input().strip())
    planting_times = list(map(int, input().strip().split()))
    growing_times = list(map(int, input().strip().split()))
    print(earliest_full_bloom(N, planting_times, growing_times))

if __name__ == "__main__":
    main()

In the code above, the `earliest_full_bloom` function first sorts the planting times and the growing times. Then it iterates through the sorted lists and keeps track of the earliest bloom day by adding the planting time and the growing time of the next plant to the current earliest bloom day. The `main` function reads the input and calls the `earliest_full_bloom` function.