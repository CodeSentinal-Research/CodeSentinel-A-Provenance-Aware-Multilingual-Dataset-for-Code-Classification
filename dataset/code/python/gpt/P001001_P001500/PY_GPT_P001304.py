# problem title : Minimum Cost to Cut a Board
# Solve the stated task using standard input and standard output.
from typing import List

def min_cost_cut_board(x: List[int], y: List[int]) -> int:
    x.sort(reverse=True)
    y.sort(reverse=True)

    h_pieces, v_pieces = 1, 1
    i, j = 0, 0
    total_cost = 0

    while i < len(x) and j < len(y):
        if x[i] >= y[j]:
            total_cost += x[i] * v_pieces
            h_pieces += 1
            i += 1
        else:
            total_cost += y[j] * h_pieces
            v_pieces += 1
            j += 1

    while i < len(x):
        total_cost += x[i] * v_pieces
        i += 1

    while j < len(y):
        total_cost += y[j] * h_pieces
        j += 1

    return total_cost

if __name__ == '__main__':
    m, n = map(int, input().split())
    x = list(map(int, input().split()))
    y = list(map(int, input().split()))
    print(min_cost_cut_board(x, y))
