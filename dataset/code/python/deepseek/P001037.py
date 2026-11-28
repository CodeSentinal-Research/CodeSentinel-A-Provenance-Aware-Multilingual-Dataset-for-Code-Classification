def solve_tasks(n, tasks, k):
    frequencies = {}
    for task in tasks:
        if task in frequencies:
            frequencies[task] += 1
        else:
            frequencies[task] = 1

    tasks = sorted(frequencies, key=lambda task: (-frequencies[task], task))

    max_cooling = k
    for task in tasks:
        max_cooling = max(max_cooling, task)

    return max_cooling


def main():
    n = int(input().strip())

    tasks = input().strip().split()

    k = int(input().strip())

    result = solve_tasks(n, tasks, k)

    print(result)


if __name__ == "__main__":
    main()
This code first reads the number of tasks and the cooling interval, then it solves the tasks by creating a list of tasks sorted by frequency (descending) and by length of cooling time (ascending). It calculates the maximum cooling time and prints this value.