import sys

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        s, c = lines[0], lines[1][0]
        print(s.count(c))

if __name__ == '__main__':
    main()