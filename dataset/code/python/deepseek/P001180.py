def max_happiness():
    N = int(input())
    activities = [list(map(int, input().split())) for _ in range(N)]
    memo = dict()

    def dp(i, prev):
        if i == N:
            return 0
        if (i, prev) in memo:
            return memo[(i, prev)]
        max_happiness = 0
        for activity in activities[i]:
            if activity != prev:
                max_happiness = max(max_happiness, activity + dp(i + 1, activity))
        memo[(i, prev)] = max_happiness
        return memo[(i, prev)]

    print(dp(0, None))

if __name__ == "__main__":
    max_happiness()