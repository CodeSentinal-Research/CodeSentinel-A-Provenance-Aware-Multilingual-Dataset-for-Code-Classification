s = int(input())
h = s // 3600
rem = s % 3600
m = rem // 60
sec = rem % 60
print(h, m, sec)
