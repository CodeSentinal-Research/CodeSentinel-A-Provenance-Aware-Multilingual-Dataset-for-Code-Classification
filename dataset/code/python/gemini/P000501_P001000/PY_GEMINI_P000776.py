import sys
def word_break_partitions(s, dict_words):
    words = set(dict_words)
    res = []
    def backtrack(idx, cur):
        if idx == len(s):
            res.append(list(cur))
            return
        for end in range(idx + 1, len(s) + 1):
            w = s[idx:end]
            if w in words:
                backtrack(end, cur + [w])
    backtrack(0, [])
    return sorted(res)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s = tokens[0]
        m = int(tokens[1])
        dict_words = tokens[2:2+m]
        for part in word_break_partitions(s, dict_words):
            print(*part)
if __name__ == '__main__':
    main()