def minimum_unfairness():
    N, K = map(int, input().split())
    bags = list(map(int, input().split()))

    bags.sort()

    unfairness = float('inf')

    for i in range(N - K + 1):
        unfairness = min(unfairness, bags[i+K-1] - bags[i])

    print(unfairness)

minimum_unfairness()