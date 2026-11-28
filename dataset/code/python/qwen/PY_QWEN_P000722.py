import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    if sum(arr) % 4 != 0: print("false"); return
    target = sum(arr) // 4
    arr.sort(reverse=True)
    def rec(idx, sides):
        if idx == n: return all(s == target for s in sides)
        for i in range(4):
            if sides[i] + arr[idx] <= target:
                sides[i] += arr[idx]
                if rec(idx + 1, sides): return True
                sides[i] -= arr[idx]
            if sides[i] == 0: break
        return False
    print("true" if rec(0, [0]*4) else "false")
solve()
