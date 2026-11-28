Here is the Python code for the problem:

def max_capital():
    N, K, InitialCapital = map(int, input().split())
    projects = []
    for _ in range(N):
        capital, profit = map(int, input().split())
        projects.append((capital, profit))
    projects.sort(key=lambda x: x[1] * x[0])
    projects.reverse()
    capital = InitialCapital
    for project in projects:
        if capital >= project[0]:
            capital += project[1]
            K -= 1
            if K == 0:
                return capital
    return capital

print(max_capital())

This code first reads the number of projects, the number of projects to be done, and the initial capital. Then it reads the capital and profit of each project. The projects are sorted by the profit multiplied by the capital, which means that the projects that require more capital but have a higher profit are prioritized. After sorting, the projects are reversed to make sure the one with the highest profit is done first. The code then iterates over the sorted projects, adding the capital of each project to the total capital if it allows the additional projects to be done. The code will return the final capital after all projects are done.