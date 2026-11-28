import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        b = lines[0]
        print(int(b, 2))
if __name__ == '__main__':
    main()