import sys

def find_the_difference(s: str, t: str) -> str:
    code = 0
    for c in s + t:
        code ^= ord(c)
    return chr(code)

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print(find_the_difference(lines[0], lines[1]))
    elif len(lines) == 1:
        print(lines[0])

if __name__ == '__main__':
    main()