import sys

def word_pattern(pattern: str, s: str) -> bool:
    words = s.split()
    if len(pattern) != len(words): return False
    pw, wp = {}, {}
    for p, w in zip(pattern, words):
        if (p in pw and pw[p] != w) or (w in wp and wp[w] != p):
            return False
        pw[p] = w
        wp[w] = p
    return True

def main():
    lines = sys.stdin.read().strip().split('\n')
    if len(lines) >= 2:
        print("Yes" if word_pattern(lines[0].strip(), lines[1].strip()) else "No")
    elif len(lines) == 1:
        parts = lines[0].split()
        if len(parts) >= 2:
            print("Yes" if word_pattern(parts[0], " ".join(parts[1:])) else "No")

if __name__ == '__main__':
    main()