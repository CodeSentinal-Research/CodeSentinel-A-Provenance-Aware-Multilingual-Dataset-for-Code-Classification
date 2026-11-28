# PY_GPT_P001571 - Maximum Difference Between First and Last Element in Every Window
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
out = []
for left in range(n - k + 1):
    w = a[left:left + k]
    out.append(w[-1] - w[0])
print(*out)
