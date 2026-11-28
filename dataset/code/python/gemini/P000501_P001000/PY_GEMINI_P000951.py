def sum_of_totients(n: int) -> int:
    phi = list(range(n + 1))
    for i in range(2, n + 1):
        if phi[i] == i:
            for j in range(i, n + 1, i):
                phi[j] -= phi[j] // i
    return sum(phi[1:])

if __name__ == '__main__':
    n = int(input())
    print(sum_of_totients(n))