from typing import List

def defense_of_kingdom(w: int, h: int, towers: List[List[int]]) -> int:
    xs = [0] + sorted(t[0] for t in towers) + [w + 1]
    ys = [0] + sorted(t[1] for t in towers) + [h + 1]

    max_dx = max(xs[i] - xs[i - 1] - 1 for i in range(1, len(xs)))
    max_dy = max(ys[i] - ys[i - 1] - 1 for i in range(1, len(ys)))

    return max_dx * max_dy

if __name__ == '__main__':
    w, h, n = map(int, input().split())
    towers = [list(map(int, input().split())) for _ in range(n)]
    print(defense_of_kingdom(w, h, towers))