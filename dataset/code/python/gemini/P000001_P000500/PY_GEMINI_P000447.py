import sys
import bisect
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        target = int(tokens[1])
        arr = list(map(int, tokens[2:2+n]))
        left = bisect.bisect_left(arr, target)
        if left < n and arr[left] == target:
            right = bisect.bisect_right(arr, target) - 1
            print(left, right)
        else:
            print("-1 -1")
if __name__ == '__main__':
    main()