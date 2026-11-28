import sys
def comb_sum(cands, target, idx, cur):
    if target == 0:
        print(*cur)
        return
    if target < 0 or idx >= len(cands):
        return
    # Pick current candidate
    comb_sum(cands, target - cands[idx], idx, cur + [cands[idx]])
    # Skip current candidate
    comb_sum(cands, target, idx + 1, cur)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        cands = sorted(list(map(int, tokens[1:1+n])))
        target = int(tokens[1+n])
        comb_sum(cands, target, 0, [])
if __name__ == '__main__':
    main()