import sys

def title_to_number(columnTitle: str) -> int:
    res = 0
    for c in columnTitle:
        res = res * 26 + (ord(c) - ord('A') + 1)
    return res

def main():
    lines = sys.stdin.read().split()
    if lines:
        print(title_to_number(lines[0]))

if __name__ == '__main__':
    main()