# PY_GPT_P001529 - Count Subarrays With Exactly K Distinct Elements
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))

def count(limit):
    if limit < 0:
        return 0
    freq = {}
    left = total = 0
    for right, x in enumerate(a):
        freq[x] = freq.get(x, 0) + 1
        while len(freq) > limit:
            y = a[left]
            freq[y] -= 1
            if freq[y] == 0:
                del freq[y]
            left += 1
        total += right - left + 1
    return total
print(count(k) - count(k - 1))
