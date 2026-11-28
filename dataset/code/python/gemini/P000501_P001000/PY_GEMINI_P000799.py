import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        m = int(tokens[1])
        idx = 2
        grid = []
        for _ in range(n):
            grid.append(list(map(int, tokens[idx:idx+m])))
            idx += m
        pref = [[0]*m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                pref[i][j] = grid[i][j]
                if i > 0: pref[i][j] += pref[i - 1][j]
                if j > 0: pref[i][j] += pref[i][j - 1]
                if i > 0 and j > 0: pref[i][j] -= pref[i - 1][j - 1]
        for row in pref:
            print(*row)
if __name__ == '__main__':
    main()