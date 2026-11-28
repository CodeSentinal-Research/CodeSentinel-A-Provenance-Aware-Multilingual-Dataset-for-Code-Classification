import sys
def can_ship(arr, d, cap):
    days = 1
    curr = 0
    for w in arr:
        if curr + w > cap:
            days += 1
            curr = w
        else:
            curr += w
    return days <= d

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        d = int(tokens[1])
        arr = list(map(int, tokens[2:2+n]))
        l, r = max(arr), sum(arr)
        ans = r
        while l <= r:
            # Calculate midpoint to prevent potential overflow
            mid = (l + r) // 2
            if can_ship(arr, d, mid):
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        print(ans)
if __name__ == '__main__':
    main()