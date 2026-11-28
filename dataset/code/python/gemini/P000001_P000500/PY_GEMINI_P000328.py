import sys
from collections import Counter

def first_uniq_char(s: str) -> int:
    cnt = Counter(s)
    for i, c in enumerate(s):
        if cnt[c] == 1:
            return i
    return -1

def main():
    lines = sys.stdin.read().split()
    if lines:
        print(first_uniq_char(lines[0]))

if __name__ == '__main__':
    main()