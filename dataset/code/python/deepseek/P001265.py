def max_performance():
    N, K = map(int, input().split())
    speeds = list(map(int, input().split()))
    efficiencies = list(map(int, input().split()))

    engineers = list(zip(speeds, efficiencies))

    engineers.sort(key=lambda x: -x[1])

    max_speed = sum(speed for speed, _ in engineers[:K])

    print(max_speed)

max_performance()