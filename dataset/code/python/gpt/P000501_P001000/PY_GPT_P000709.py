# problem title : Generate All Permutations of a String
# Solve the stated task using standard input and standard output.
import sys
def perm(s, cur, used, res):
    if len(cur) == len(s):
        res.append(cur)
        return
    for i in range(len(s)):
        if not used[i]:
            used[i] = True
            perm(s, cur + s[i], used, res)
            used[i] = False
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s = sorted(tokens[0])
        res = []
        perm(s, "", [False]*len(s), res)
        for p in res:
            print(p)
if __name__ == '__main__':
    main()
