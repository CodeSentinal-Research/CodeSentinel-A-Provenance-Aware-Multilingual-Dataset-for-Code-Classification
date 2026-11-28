import sys
from collections import Counter

def same_characters(s1: str, s2: str) -> bool:
    return Counter(s1) == Counter(s2)

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print("Yes" if same_characters(lines[0], lines[1]) else "No")

if __name__ == '__main__':
    main()