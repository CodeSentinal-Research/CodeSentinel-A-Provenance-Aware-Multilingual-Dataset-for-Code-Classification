import sys
def case_perm(s, idx, cur, res):
    if idx == len(s):
        res.append(cur)
        return
    ch = s[idx]
    if ch.isalpha():
        case_perm(s, idx + 1, cur + ch.lower(), res)
        case_perm(s, idx + 1, cur + ch.upper(), res)
    else:
        case_perm(s, idx + 1, cur + ch, res)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s = tokens[0]
        res = []
        case_perm(s, 0, "", res)
        res.sort()
        for p in res:
            print(p)
if __name__ == '__main__':
    main()