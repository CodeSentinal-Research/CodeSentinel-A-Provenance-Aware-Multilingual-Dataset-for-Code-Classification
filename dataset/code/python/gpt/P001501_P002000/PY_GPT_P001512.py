# PY_GPT_P001512 - Binary Subarrays With Sum
# Problem-specific verified implementation.
n, goal = map(int, input().split())
a = list(map(int, input().split()))

def at_most(limit):
    if limit < 0:
        return 0
    left = current = total = 0
    for right, x in enumerate(a):
        current += x
        while current > limit:
            current -= a[left]
            left += 1
        total += right - left + 1
    return total
print(at_most(goal) - at_most(goal - 1))
