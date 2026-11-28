import sys
from collections import Counter

def can_construct(ransom_note: str, magazine: str) -> bool:
    c_note, c_mag = Counter(ransom_note), Counter(magazine)
    return not (c_note - c_mag)

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print("Yes" if can_construct(lines[0], lines[1]) else "No")

if __name__ == '__main__':
    main()