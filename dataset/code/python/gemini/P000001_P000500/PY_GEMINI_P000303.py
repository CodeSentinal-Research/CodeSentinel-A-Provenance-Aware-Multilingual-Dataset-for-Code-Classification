import sys

def word_break_ii(s: str, word_dict: set):
    memo = {}
    def dfs(rem):
        if rem in memo:
            return memo[rem]
        if not rem:
            return [""]
        res = []
        for word in word_dict:
            if rem.startswith(word):
                sub_res = dfs(rem[len(word):])
                for sub in sub_res:
                    res.append(word + (" " + sub if sub else ""))
        memo[rem] = res
        return res
    return dfs(s)

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s = tokens[0]
        words = set(tokens[1:])
        for sentence in word_break_ii(s, words):
            print(sentence)

if __name__ == '__main__':
    main()