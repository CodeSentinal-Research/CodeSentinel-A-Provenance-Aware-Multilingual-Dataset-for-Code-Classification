import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        l, r = 1, n
        is_sq = False
        while l <= r:
            # Calculate midpoint to prevent potential overflow
            mid = (l + r) // 2
            sq = mid * mid
            if sq == n:
                is_sq = True
                break
            elif sq < n:
                l = mid + 1
            else:
                r = mid - 1
        print("Yes" if is_sq else "No")
if __name__ == '__main__':
    main()