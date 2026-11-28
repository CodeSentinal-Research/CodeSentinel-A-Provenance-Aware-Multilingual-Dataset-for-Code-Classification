n = int(input())
arr = list(map(int, input().split()))
pos = 0
neg = 0
max_len = 0
first_neg = -1
for i, x in enumerate(arr):
    if x == 0:
        pos = 0
        neg = 0
        first_neg = -1
    elif x > 0:
        pos += 1
        if neg > 0:
            neg += 1
    else:
        pos, neg = neg, pos + 1
        if first_neg == -1:
            first_neg = i
    if neg > 0:
        max_len = max(max_len, neg)
    else:
        max_len = max(max_len, pos)
print(max_len)
