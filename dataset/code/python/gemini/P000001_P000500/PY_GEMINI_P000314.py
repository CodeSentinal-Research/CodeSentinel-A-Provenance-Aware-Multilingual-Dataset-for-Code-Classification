import sys

def convert_to_title(columnNumber: int) -> str:
    res = []
    while columnNumber > 0:
        columnNumber -= 1
        res.append(chr(ord('A') + (columnNumber % 26)))
        columnNumber //= 26
    return "".join(reversed(res))

def main():
    lines = sys.stdin.read().split()
    if lines:
        print(convert_to_title(int(lines[0])))

if __name__ == '__main__':
    main()