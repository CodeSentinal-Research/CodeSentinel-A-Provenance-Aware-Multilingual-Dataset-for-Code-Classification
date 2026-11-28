# PY_GPT_P001595 - Sum Between Two Positions
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
l, r = map(int, input().split())
print(sum(a[l:r + 1]))
