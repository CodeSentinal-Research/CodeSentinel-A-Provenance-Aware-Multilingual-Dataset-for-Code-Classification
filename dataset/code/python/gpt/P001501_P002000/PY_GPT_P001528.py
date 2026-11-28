# PY_GPT_P001528 - Count Subarrays With At Most K Distinct Elements
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
freq = {}
left = answer = 0
for right, x in enumerate(a):
    freq[x] = freq.get(x, 0) + 1
    while len(freq) > k:
        y = a[left]
        freq[y] -= 1
        if freq[y] == 0:
            del freq[y]
        left += 1
    answer += right - left + 1
print(answer)
