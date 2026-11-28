def minimumRefuelStops(distance, initialFuel, numStations, stations):
    if distance <= initialFuel:
        return 0

    dp = [0] * (numStations + 1)
    dp[0] = initialFuel
    for i in range(1, numStations + 1):
        dp[i] = max(dp[i - 1], stations[i - 1])
        for j in range(i - 1, -1, -1):
            dp[i] = max(dp[i], dp[j] + stations[i - 1])
        if dp[i] >= distance:
            return i

    if dp[-1] >= distance:
        return -1
    else:
        return -2


def main():
    distance = int(input())
    initialFuel = int(input())
    numStations = int(input())
    stations = list(map(int, input().split()))
    print(minimumRefuelStops(distance, initialFuel, numStations, stations))


if __name__ == "__main__":
    main()