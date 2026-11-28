# problem title : Check Armstrong Number
n = int(input())
s = str(n)
p = len(s)
print("Armstrong" if sum(int(d) ** p for d in s) == n else "Not Armstrong")
