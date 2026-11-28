import sys

def repeated_substring_pattern(s: str) -> bool:
    return s in (s + s)[1:-1]

def main():
    lines = sys.stdin.read().split()
    if lines:
        print("Yes" if repeated_substring_pattern(lines[0]) else "No")

if __name__ == '__main__':
    main()