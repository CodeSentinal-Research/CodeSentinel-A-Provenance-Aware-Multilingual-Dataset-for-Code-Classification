# PY_GPT_P001570 - Longest Continuous Subarray With Positive Product
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
positive = negative = best = 0
for x in a:
    if x > 0:
        positive, negative = (positive + 1, negative + 1 if negative else 0)
    elif x < 0:
        positive, negative = (negative + 1 if negative else 0, positive + 1)
    else:
        positive = negative = 0
    best = max(best, positive)
print(best)
