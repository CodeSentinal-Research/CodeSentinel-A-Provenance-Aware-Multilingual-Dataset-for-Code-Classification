import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        print(ord(lines[0][0]))
if __name__ == '__main__':
    main()