n = input().strip()
p = len(n)
s = sum(int(x) ** p for x in n)
if s == int(n):
    print("Armstrong")
else:
    print("Not Armstrong")
