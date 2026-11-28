# PY_GPT_P001517 - Minimize Maximum Pair Sum
# Problem-specific verified implementation.
n = int(input())
a = sorted(map(int, input().split()))
print(max((a[i] + a[n - 1 - i] for i in range(n // 2))))
