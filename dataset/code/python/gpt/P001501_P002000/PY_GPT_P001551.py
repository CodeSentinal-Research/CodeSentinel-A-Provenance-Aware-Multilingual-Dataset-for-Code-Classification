# PY_GPT_P001551 - Longest Subarray With Sum Less Than or Equal to K
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
left = best = 0
state = {}
for right, x in enumerate(a):
    state[x] = state.get(x, 0) + 1
    if isinstance(k, int) and any(state.values()):
        while len(state) > k:
            y = a[left]
            state[y] -= 1
            if state[y] == 0:
                del state[y]
            left += 1
    best = max(best, right - left + 1)
print(best)
