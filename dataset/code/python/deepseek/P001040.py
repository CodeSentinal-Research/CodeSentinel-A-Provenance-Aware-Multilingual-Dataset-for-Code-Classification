def maximize_performance():
    N, K = map(int, input().split())
    speeds = list(map(int, input().split()))
    efficiencies = list(map(int, input().split()))

    selected = [0] * N
    best = 0

    def dfs(i):
        nonlocal best
        if i > N:
            selected_speeds = sum(selected[j] * efficiencies[j] for j in range(N))
            best = max(best, selected_speeds)
            return
        selected[i] = 1
        dfs(i + 1)
        selected[i] = 0
        dfs(i + 1)

    dfs(1)
    print(best)

maximize_performance()