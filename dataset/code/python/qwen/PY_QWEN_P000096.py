n = input().strip()
s = sum(int(x) for x in n)
p = 1
for x in n:
    p *= int(x)
if s == p:
    print("Spy")
else:
    print("Not Spy")
