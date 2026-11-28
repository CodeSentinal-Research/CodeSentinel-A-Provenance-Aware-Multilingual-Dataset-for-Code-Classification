import sys
import math
def can_finish(arr, h, speed):
    hours = sum(math.ceil(p / speed) for p in arr)
    return hours <= h

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        h = int(tokens[1])
        arr = list(map(int, tokens[2:2+n]))
        l, r = 1, max(arr)
        ans = r
        while l <= r:
            # Calculate midpoint to prevent potential overflow
            mid = (l + r) // 2
            if can_finish(arr, h, mid):
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        print(ans)
if __name__ == '__main__':
    main()