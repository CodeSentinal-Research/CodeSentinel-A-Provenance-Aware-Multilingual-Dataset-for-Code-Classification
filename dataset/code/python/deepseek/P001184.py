def min_energy():
    N, K = map(int, input().split())
    stones = list(map(int, input().split()))

    stones.sort()
    energy = 0

    for i in range(N - 1):
        energy += abs(stones[i] - stones[i + 1])

    return energy


print(min_energy())