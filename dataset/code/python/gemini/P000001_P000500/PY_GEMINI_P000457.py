import sys
import math
def check(arr, thresh, div):
    return sum(math.ceil(v / div) for v in arr) <= thresh

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        thresh = int(tokens[1])
        arr = list(map(int, tokens[2:2+n]))
        l, r = 1, max(arr)
        ans = r
        while l <= r:
            # Calculate midpoint to prevent potential overflow
            mid = (l + r) // 2
            if check(arr, thresh, mid):
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        print(ans)
if __name__ == '__main__':
    main()