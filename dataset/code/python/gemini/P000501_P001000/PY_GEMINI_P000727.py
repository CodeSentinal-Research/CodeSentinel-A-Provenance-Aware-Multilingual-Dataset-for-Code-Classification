import sys
def word_break(s, word_dict):
    words = set(word_dict)
    memo = {}
    def backtrack(idx):
        if idx in memo: return memo[idx]
        if idx == len(s): return [""]
        res = []
        for end in range(idx + 1, len(s) + 1):
            w = s[idx:end]
            if w in words:
                sub = backtrack(end)
                for sent in sub:
                    res.append((w + " " + sent).strip())
        memo[idx] = res
        return res
    ans = backtrack(0)
    return sorted(ans)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s = tokens[0]
        m = int(tokens[1])
        dict_words = tokens[2:2+m]
        for sent in word_break(s, dict_words):
            print(sent)
if __name__ == '__main__':
    main()