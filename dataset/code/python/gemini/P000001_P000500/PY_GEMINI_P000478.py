import sys
def can_place(arr, c, dist):
    count = 1
    last = arr[0]
    for x in arr[1:]:
        if x - last >= dist:
            count += 1
            last = x
            if count >= c: return True
    return count >= c

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        c = int(tokens[1])
        arr = sorted(list(map(int, tokens[2:2+n])))
        l, r = 1, arr[-1] - arr[0]
        ans = 1
        while l <= r:
            # Calculate midpoint to prevent potential overflow
            mid = (l + r) // 2
            if can_place(arr, c, mid):
                ans = mid
                l = mid + 1
            else:
                r = mid - 1
        print(ans)
if __name__ == '__main__':
    main()