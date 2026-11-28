import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    moves = []
    def rec(num, src, aux, dst):
        if num == 1:
            moves.append(f"{src} {dst}")
            return
        rec(num - 1, src, dst, aux)
        moves.append(f"{src} {dst}")
        rec(num - 1, aux, src, dst)
    rec(n, 1, 2, 3)
    for m in moves: print(m)
    print(len(moves))
solve()
