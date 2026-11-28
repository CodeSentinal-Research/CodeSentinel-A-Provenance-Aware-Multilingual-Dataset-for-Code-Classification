import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        n = int(lines[0])
        arr = lines[1:n+1]
        rotated = [arr[-1]] + arr[:-1]
        print(' '.join(rotated))
if __name__ == '__main__':
    main()