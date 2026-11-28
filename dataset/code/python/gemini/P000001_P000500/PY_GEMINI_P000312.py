import sys

def compare_version(v1: str, v2: str) -> int:
    p1 = list(map(int, v1.split('.')))
    p2 = list(map(int, v2.split('.')))
    max_len = max(len(p1), len(p2))
    p1.extend([0] * (max_len - len(p1)))
    p2.extend([0] * (max_len - len(p2)))
    for a, b in zip(p1, p2):
        if a < b: return -1
        elif a > b: return 1
    return 0

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print(compare_version(lines[0], lines[1]))

if __name__ == '__main__':
    main()