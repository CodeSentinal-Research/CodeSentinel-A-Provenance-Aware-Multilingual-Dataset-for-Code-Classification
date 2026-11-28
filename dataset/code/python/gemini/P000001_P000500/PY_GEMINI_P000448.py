import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        l, r, ans = 0, n, 0
        while l <= r:
            # Calculate midpoint to prevent potential overflow
            mid = (l + r) // 2
            if mid * mid <= n:
                ans = mid
                l = mid + 1
            else:
                r = mid - 1
        print(ans)
if __name__ == '__main__':
    main()