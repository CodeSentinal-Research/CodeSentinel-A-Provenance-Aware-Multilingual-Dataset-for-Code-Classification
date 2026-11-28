def max_capital():
    N, K = map(int, input().split())
    capital_requirements = list(map(int, input().split()))
    profits = list(map(int, input().split()))
    initial_capital = int(input())

    projects = list(zip(capital_requirements, profits))
    projects.sort(key=lambda x: -x[1])

    current_capital = initial_capital
    for i in range(K):
        if current_capital < projects[i][0]:
            break
        current_capital += projects[i][1]

    print(current_capital)

max_capital()