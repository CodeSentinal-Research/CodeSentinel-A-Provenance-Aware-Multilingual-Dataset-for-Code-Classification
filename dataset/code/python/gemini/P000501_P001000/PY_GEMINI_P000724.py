import sys
def max_length(words):
    masks = []
    for w in words:
        m = 0
        dup = False
        for ch in w:
            b = 1 << (ord(ch) - ord('a'))
            if m & b: dup = True; break
            m |= b
        if not dup: masks.append((m, len(w)))
    ans = [0]
    def backtrack(idx, cur_m, cur_len):
        ans[0] = max(ans[0], cur_len)
        for i in range(idx, len(masks)):
            m, l = masks[i]
            if not (cur_m & m):
                backtrack(i + 1, cur_m | m, cur_len + l)
    backtrack(0, 0, 0)
    return ans[0]
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        words = tokens[1:1+n]
        print(max_length(words))
if __name__ == '__main__':
    main()