sizes = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
i = j = k = 0
res = []
while i < sizes[0] and j < sizes[1] and k < sizes[2]:
    if a[i] == b[j] == c[k]:
        if not res or res[-1] != a[i]:
            res.append(a[i])
        i += 1
        j += 1
        k += 1
    elif a[i] < b[j]:
        i += 1
    elif b[j] < c[k]:
        j += 1
    else:
        k += 1
print(" ".join(map(str, res)))
