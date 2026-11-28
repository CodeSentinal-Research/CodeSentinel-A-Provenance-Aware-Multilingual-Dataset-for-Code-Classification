import sys

def reverse_str(s: str, k: int) -> str:
    a = list(s)
    for i in range(0, len(a), 2 * k):
        a[i:i+k] = reversed(a[i:i+k])
    return "".join(a)

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print(reverse_str(lines[0], int(lines[1])))

if __name__ == '__main__':
    main()