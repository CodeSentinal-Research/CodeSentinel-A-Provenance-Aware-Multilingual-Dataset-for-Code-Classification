import sys

def check_record(s: str) -> bool:
    return s.count('A') < 2 and 'LLL' not in s

def main():
    lines = sys.stdin.read().split()
    if lines:
        print("Yes" if check_record(lines[0]) else "No")

if __name__ == '__main__':
    main()