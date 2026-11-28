import sys

def find_words(words):
    r1, r2, r3 = set("qwertyuiop"), set("asdfghjkl"), set("zxcvbnm")
    res = []
    for w in words:
        lower_w = set(w.lower())
        if lower_w <= r1 or lower_w <= r2 or lower_w <= r3:
            res.append(w)
    return res

def main():
    words = sys.stdin.read().split()
    if words:
        for w in find_words(words):
            print(w)

if __name__ == '__main__':
    main()