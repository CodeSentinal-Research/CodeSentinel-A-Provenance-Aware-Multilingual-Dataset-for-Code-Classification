import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        m = int(tokens[1])
        idx = 2
        pref = [[0]*(m + 1) for _ in range(n + 1)]
        for i in range(n):
            for j in range(m):
                val = int(tokens[idx])
                pref[i + 1][j + 1] = val + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]
                idx += 1
        k = int(tokens[idx])
        ans = [[0]*m for _ in range(n)]
        for i in range(n):
            r1 = max(0, i - k)
            r2 = min(n - 1, i + k)
            for j in range(m):
                c1 = max(0, j - k)
                c2 = min(m - 1, j + k)
                ans[i][j] = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1]
        for row in ans:
            print(*row)
if __name__ == '__main__':
    main()