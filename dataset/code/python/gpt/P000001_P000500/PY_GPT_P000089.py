# problem title : Find Square Root without Built-in Function
# Binary search gives floor(sqrt(n)) without calling a square-root function.
n = int(input())
lo, hi, answer = 0, n, 0
while lo <= hi:
    mid = (lo + hi) // 2
    if mid * mid <= n:
        answer = mid
        lo = mid + 1
    else:
        hi = mid - 1
print(answer)
