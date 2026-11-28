import sys
import bisect
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        target = int(tokens[1])
        arr = list(map(int, tokens[2:2+n]))
        print(bisect.bisect_left(arr, target))
if __name__ == '__main__':
    main()