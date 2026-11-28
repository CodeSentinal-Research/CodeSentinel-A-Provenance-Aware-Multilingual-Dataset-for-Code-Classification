from itertools import combinations

def solve(n, k):
    combinations_obj = combinations(range(1, n+1), k)
    combinations_list = list(combinations_obj)
    combinations_list.sort()

    for combination in combinations_list:
        print(combination)

if __name__ == '__main__':
    n, k = map(int, input().split())
    solve(n, k)