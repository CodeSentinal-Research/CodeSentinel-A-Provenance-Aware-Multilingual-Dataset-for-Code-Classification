import sys
def can_split(arr, m, max_sum):
    count = 1
    curr = 0
    for v in arr:
        if curr + v > max_sum:
            count += 1
            curr = v
        else:
            curr += v
    return count <= m

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        m = int(tokens[1])
        arr = list(map(int, tokens[2:2+n]))
        l, r = max(arr), sum(arr)
        ans = r
        while l <= r:
            # Calculate midpoint to prevent potential overflow
            mid = (l + r) // 2
            if can_split(arr, m, mid):
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        print(ans)
if __name__ == '__main__':
    main()