# PY_GPT_P001503 - Minimum Adjacent Swaps for K Consecutive Ones
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
pos = [i for i, x in enumerate(a) if x]
prefix = [0]
for x in pos:
    prefix.append(prefix[-1] + x)
answer = 10 ** 30
for left in range(len(pos) - k + 1):
    right = left + k - 1
    mid = (left + right) // 2
    m = pos[mid]
    lc = mid - left
    rc = right - mid
    cost = m * lc - (prefix[mid] - prefix[left])
    cost += prefix[right + 1] - prefix[mid + 1] - m * rc
    cost -= lc * (lc + 1) // 2 + rc * (rc + 1) // 2
    answer = min(answer, cost)
print(answer)
