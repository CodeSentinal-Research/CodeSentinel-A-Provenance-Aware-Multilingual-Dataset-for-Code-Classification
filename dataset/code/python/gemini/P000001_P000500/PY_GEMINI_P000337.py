import sys

def max_score(s: str) -> int:
    max_val = 0
    for i in range(1, len(s)):
        score = s[:i].count('0') + s[i:].count('1')
        max_val = max(max_val, score)
    return max_val

def main():
    lines = sys.stdin.read().split()
    if lines:
        print(max_score(lines[0]))

if __name__ == '__main__':
    main()