# problem title : Maximum Side Length of a Square with Sum at Most Threshold
# Solve the stated task using standard input and standard output.
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
        threshold = int(tokens[idx])
        def get_sum(r1, c1, r2, c2):
            return pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1]
        max_len = 0
        for i in range(n):
            for j in range(m):
                while (i + max_len < n and j + max_len < m and
                       get_sum(i, j, i + max_len, j + max_len) <= threshold):
                    max_len += 1
        print(max_len)
if __name__ == '__main__':
    main()
