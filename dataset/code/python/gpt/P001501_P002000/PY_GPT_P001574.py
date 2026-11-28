# PY_GPT_P001574 - Maximum Element in the First Window
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
print(max(a[:k]))
