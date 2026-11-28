import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        s = lines[0].lstrip('-')
        print(sum(1 for ch in s if ch.isdigit() and int(ch) % 2 != 0))
if __name__ == '__main__':
    main()