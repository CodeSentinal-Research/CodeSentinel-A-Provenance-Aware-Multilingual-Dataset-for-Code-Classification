def phi_1_to_n(n: int):
    phi = list(range(n + 1))
    for i in range(2, n + 1):
        if phi[i] == i:
            for j in range(i, n + 1, i):
                phi[j] -= phi[j] // i
    return phi[1:]

if __name__ == '__main__':
    n = int(input())
    res = phi_1_to_n(n)
    print(" ".join(map(str, res)))