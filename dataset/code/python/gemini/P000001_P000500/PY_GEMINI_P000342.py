import sys

def replace_digits(s: str) -> str:
    res = list(s)
    for i in range(1, len(s), 2):
        res[i] = chr(ord(res[i-1]) + int(res[i]))
    return "".join(res)

def main():
    lines = sys.stdin.read().split()
    if lines:
        print(replace_digits(lines[0]))

if __name__ == '__main__':
    main()