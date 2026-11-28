import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        arr = list(map(int, tokens[1:1+n]))
        l, r = 0, n - 1
        while l < r:
            # Calculate midpoint to prevent potential overflow
            mid = (l + r) // 2
            if arr[mid] > arr[mid + 1]:
                r = mid
            else:
                l = mid + 1
        print(l)
if __name__ == '__main__':
    main()