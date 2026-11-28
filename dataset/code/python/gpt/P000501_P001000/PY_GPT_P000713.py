# problem title : Combination Sum II
# Solve the stated task using standard input and standard output.
import sys
def comb_sum2(cands, target, idx, cur):
    if target == 0:
        print(*cur)
        return
    for i in range(idx, len(cands)):
        if i > idx and cands[i] == cands[i - 1]:
            continue
        if cands[i] > target:
            break
        comb_sum2(cands, target - cands[i], i + 1, cur + [cands[i]])
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        cands = sorted(list(map(int, tokens[1:1+n])))
        target = int(tokens[1+n])
        comb_sum2(cands, target, 0, [])
if __name__ == '__main__':
    main()
