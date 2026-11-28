import sys
def is_valid(arr, n, m, max_pages):
    students = 1
    curr = 0
    for p in arr:
        if p > max_pages: return False
        if curr + p > max_pages:
            students += 1
            curr = p
            if students > m: return False
        else:
            curr += p
    return True

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        m = int(tokens[1])
        arr = list(map(int, tokens[2:2+n]))
        if m > n:
            print(-1)
            return
        l, r = max(arr), sum(arr)
        ans = r
        while l <= r:
            # Calculate midpoint to prevent potential overflow
            mid = (l + r) // 2
            if is_valid(arr, n, m, mid):
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        print(ans)
if __name__ == '__main__':
    main()