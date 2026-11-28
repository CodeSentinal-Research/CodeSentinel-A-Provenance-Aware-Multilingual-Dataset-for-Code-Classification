import sys

def main():
    lines = sys.stdin.read().split()
    if lines:
        s = lines[0].lstrip('-')
        print(sum(int(ch) for ch in s if ch.isdigit()))

if __name__ == '__main__':
    main()