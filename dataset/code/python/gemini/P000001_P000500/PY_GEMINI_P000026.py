import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        n = abs(int(lines[0]))
        print(len(str(n)) if n != 0 else 1)
if __name__ == '__main__':
    main()