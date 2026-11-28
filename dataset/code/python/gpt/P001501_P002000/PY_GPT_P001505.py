# PY_GPT_P001505 - Number of Subarrays With Product Less Than K
# Problem-specific verified implementation.
n, k = map(int, input().split())
a = list(map(int, input().split()))
if k <= 1:
    print(0)
else:
    left = 0
    product = 1
    answer = 0
    for right, x in enumerate(a):
        product *= x
        while product >= k:
            product //= a[left]
            left += 1
        answer += right - left + 1
    print(answer)
