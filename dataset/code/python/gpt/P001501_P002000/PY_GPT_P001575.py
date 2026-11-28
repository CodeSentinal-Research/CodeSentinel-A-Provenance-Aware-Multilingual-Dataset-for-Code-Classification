# PY_GPT_P001575 - Minimum Element in the First Window
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
print(min(a[:k]))
