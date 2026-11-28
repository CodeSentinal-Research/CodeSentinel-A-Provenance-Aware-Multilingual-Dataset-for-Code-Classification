import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        k = int(tokens[1])
        arr = list(map(int, tokens[2:2+n]))
        l, r = 0, n - 1
        while l <= r:
            # Calculate midpoint to prevent potential overflow
            mid = (l + r) // 2
            missing = arr[mid] - (mid + 1)
            if missing < k:
                l = mid + 1
            else:
                r = mid - 1
        print(l + k)
if __name__ == '__main__':
    main()