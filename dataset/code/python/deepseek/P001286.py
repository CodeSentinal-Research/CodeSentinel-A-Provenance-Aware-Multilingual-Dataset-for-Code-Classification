def main():
    N, AdditionalRocks = map(int, input().split())
    capacities = list(map(int, input().split()))
    rocks = list(map(int, input().split()))

    max_bags = 0
    for i in range(N):
        if rocks[i] + AdditionalRocks <= capacities[i]:
            max_bags += 1
            AdditionalRocks = 0
        else:
            AdditionalRocks -= capacities[i] - rocks[i]

    print(max_bags)

if __name__ == "__main__":
    main()