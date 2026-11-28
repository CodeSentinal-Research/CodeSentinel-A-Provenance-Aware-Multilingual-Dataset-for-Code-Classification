import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        print(lines[0][0].upper())
if __name__ == '__main__':
    main()