Here is the Python code for the problem:

def solve(N, K, qualities, wages):
    sorted_qualities = sorted(zip(qualities, wages), key=lambda x: x[0], reverse=True)
    sorted_wages = sorted(wages, reverse=True)

    min_wage_diff = [sorted_wages[i] - sorted_qualities[i][1] for i in range(K)]

    min_wage = min(sorted_wages[:K])

    min_cost = sum(min_wage_diff) + min_wage * K

    return min_cost

def main():
    N, K = map(int, input().split())
    qualities = list(map(int, input().split()))
    wages = list(map(int, input().split()))
    print(solve(N, K, qualities, wages))

if __name__ == "__main__":
    main()

This program reads the number of workers (N), number of workers to hire (K), and the qualities and wages of the workers. It then sorts the qualities and wages in descending order. It calculates the minimum wage difference for each worker and the minimum wage. Finally, it calculates the minimum cost and prints it.