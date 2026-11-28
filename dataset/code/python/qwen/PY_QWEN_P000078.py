d = int(input())
y = d // 365
rem = d % 365
w = rem // 7
rem_d = rem % 7
print(y, w, rem_d)
