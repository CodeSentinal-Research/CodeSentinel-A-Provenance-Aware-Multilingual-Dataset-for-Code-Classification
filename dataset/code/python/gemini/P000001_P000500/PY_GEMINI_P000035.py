import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        print(bin(n)[2:])
if __name__ == '__main__':
    main()