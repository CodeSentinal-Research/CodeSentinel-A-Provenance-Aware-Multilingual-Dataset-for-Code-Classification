import sys

def find_lus_length(a: str, b: str) -> int:
    return -1 if a == b else max(len(a), len(b))

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print(find_lus_length(lines[0], lines[1]))

if __name__ == '__main__':
    main()