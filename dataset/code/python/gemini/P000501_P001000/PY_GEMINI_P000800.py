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
        q = int(tokens[idx])
        idx += 1
        for _ in range(q):
            r1, c1, r2, c2 = map(int, tokens[idx:idx+4])
            ans = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1]
            print(ans)
            idx += 4
if __name__ == '__main__':
    main()