Here is a Python solution for the two city scheduling problem:

def solve(N, costs):
    costs.sort(key=lambda x: x[0])

    costs.sort(key=lambda x: x[1])

    min_cost = float('inf')
    for i in range(N):
        min_cost = min(min_cost, costs[i][0] + costs[i + N][1])

    return min_cost


def main():
    N = int(input())
    costs = [list(map(int, input().split())) for _ in range(2*N)]

    print(solve(N, costs))


if __name__ == "__main__":
    main()

In this solution, we first sort the costs of sending each person to both cities by cost of person A. Then, we sort the costs of sending each person to both cities by cost of person B. Finally, we iterate over each city, choose one person A and one person B to serve as the head of the two cities, and update the minimum total cost.