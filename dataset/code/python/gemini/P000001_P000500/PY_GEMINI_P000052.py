import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        print(lines[0][0].lower())
if __name__ == '__main__':
    main()