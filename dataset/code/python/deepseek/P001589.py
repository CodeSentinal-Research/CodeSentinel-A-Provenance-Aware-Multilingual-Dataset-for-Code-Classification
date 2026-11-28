def find_longest_interval():
    N = int(input())
    days = list(map(int, input().split()))

    max_interval = 0
    curr_interval = 0

    for i in range(N):
        if days[i] > 8:
            curr_interval += 1
        else:
            max_interval = max(max_interval, curr_interval)
            curr_interval = 0

    max_interval = max(max_interval, curr_interval)

    print(max_interval)


if __name__ == "__main__":
    find_longest_interval()

This Python code reads the number of days and the hours worked for each day from the standard input, calculates the length of the longest contiguous interval where the number of tiring days is strictly greater than the number of non-tiring days, and prints the maximum length. It uses two variables, `max_interval` and `curr_interval`, to keep track of the maximum length and the current length of the longest interval, respectively.