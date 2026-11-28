def totalNQueens(n):
    def DFS(queens, left_dists, right_dists):
        p = len(queens)
        if p == n:
            res.append(queens)
            return None
        for q in range(n):
            if p == 0 or q == queens[p-1] or left_dists[p] == right_dists[p-q-1]:
                continue
            queens.append(q)
            left_dists.append(left_dists[p-1] + (q < queens[p-1]) - (q > queens[p-1]))
            right_dists.append(right_dists[p-q-1] + (q > q - p + queens[p-1]))
            DFS(queens, left_dists, right_dists)
            queens.pop()
            left_dists.pop()
            right_dists.pop()
    res = []
    DFS([], [], [])
    return len(res)


def main():
    N = int(input("Enter the value of N: "))
    print("Total number of distinct ways to place N queens on an N × N chessboard: ", totalNQueens(N))


if __name__ == "__main__":
    main()