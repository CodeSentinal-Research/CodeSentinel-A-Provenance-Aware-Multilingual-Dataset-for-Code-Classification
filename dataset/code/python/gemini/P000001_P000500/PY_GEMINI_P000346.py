import sys

def find_longest_word(s: str, words) -> str:
    words.sort(key=lambda x: (-len(x), x))
    for w in words:
        i = 0
        for c in s:
            if i < len(w) and c == w[i]:
                i += 1
        if i == len(w):
            return w
    return ""

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s = tokens[0]
        words = tokens[1:]
        print(find_longest_word(s, words))

if __name__ == '__main__':
    main()