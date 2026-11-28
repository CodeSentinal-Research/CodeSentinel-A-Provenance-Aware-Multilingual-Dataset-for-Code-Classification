import sys
from collections import Counter

def check_almost_equivalent(word1: str, word2: str) -> bool:
    c1, c2 = Counter(word1), Counter(word2)
    all_chars = set(word1) | set(word2)
    for c in all_chars:
        if abs(c1[c] - c2[c]) > 3:
            return False
    return True

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print("Yes" if check_almost_equivalent(lines[0], lines[1]) else "No")

if __name__ == '__main__':
    main()