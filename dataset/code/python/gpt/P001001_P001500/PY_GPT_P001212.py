# problem title : Boolean Parenthesization
# Solve the stated task using standard input and standard output.
def count_parenthesization(s: str) -> int:
    MOD = 1003
    n = len(s)
    symbols = [s[i] for i in range(0, n, 2)]
    operators = [s[i] for i in range(1, n, 2)]
    m = len(symbols)

    T = [[0] * m for _ in range(m)]
    F = [[0] * m for _ in range(m)]

    for i in range(m):
        T[i][i] = 1 if symbols[i] == 'T' else 0
        F[i][i] = 1 if symbols[i] == 'F' else 0

    for length in range(2, m + 1):
        for i in range(m - length + 1):
            j = i + length - 1
            for k in range(i, j):
                op = operators[k]
                total_ik = (T[i][k] + F[i][k]) % MOD
                total_kj = (T[k + 1][j] + F[k + 1][j]) % MOD

                if op == '&':
                    T[i][j] = (T[i][j] + T[i][k] * T[k + 1][j]) % MOD
                    F[i][j] = (F[i][j] + total_ik * total_kj - T[i][k] * T[k + 1][j]) % MOD
                elif op == '|':
                    F[i][j] = (F[i][j] + F[i][k] * F[k + 1][j]) % MOD
                    T[i][j] = (T[i][j] + total_ik * total_kj - F[i][k] * F[k + 1][j]) % MOD
                elif op == '^':
                    T[i][j] = (T[i][j] + T[i][k] * F[k + 1][j] + F[i][k] * T[k + 1][j]) % MOD
                    F[i][j] = (F[i][j] + T[i][k] * T[k + 1][j] + F[i][k] * F[k + 1][j]) % MOD

    return (T[0][m - 1] % MOD + MOD) % MOD

if __name__ == '__main__':
    s = input().strip()
    print(count_parenthesization(s))
