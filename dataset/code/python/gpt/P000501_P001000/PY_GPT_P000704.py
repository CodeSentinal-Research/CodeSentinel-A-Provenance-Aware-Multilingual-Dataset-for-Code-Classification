# problem title : Generate All Subsequences of a String
# Solve the stated task using standard input and standard output.
import sys
def gen_subseq(s, idx, cur, res):
    if idx == len(s):
        res.append(cur)
        return
    gen_subseq(s, idx + 1, cur, res)
    gen_subseq(s, idx + 1, cur + s[idx], res)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s = tokens[0]
        res = []
        gen_subseq(s, 0, "", res)
        res.sort()
        for x in res:
            print(x)
if __name__ == '__main__':
    main()
