import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, k = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    if sum(arr) % k != 0: print("false"); return
    target = sum(arr) // k
    arr.sort(reverse=True)
    def rec(idx, buckets):
        if idx == n: return True
        for i in range(k):
            if buckets[i] + arr[idx] <= target:
                buckets[i] += arr[idx]
                if rec(idx + 1, buckets): return True
                buckets[i] -= arr[idx]
            if buckets[i] == 0: break
        return False
    print("true" if rec(0, [0]*k) else "false")
solve()
