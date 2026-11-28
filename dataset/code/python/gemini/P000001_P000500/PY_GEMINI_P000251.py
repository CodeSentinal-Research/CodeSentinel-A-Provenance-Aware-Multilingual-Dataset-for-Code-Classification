import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        s = lines[0]
        print(s[::-1])
if __name__ == '__main__':
    main()