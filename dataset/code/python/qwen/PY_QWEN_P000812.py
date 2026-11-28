import sys
def solve():
    num = int(sys.stdin.read().split()[0])
    l, r = 1, num
    while l <= r:
        mid = (l + r) // 2
        if mid * mid == num:
            print("true")
            return
        elif mid * mid < num:
            l = mid + 1
        else:
            r = mid - 1
    print("false")
solve()
