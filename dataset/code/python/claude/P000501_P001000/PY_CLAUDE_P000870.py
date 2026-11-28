
a,b=int(input()),int(input())
while b:
    a,b=a^b,(a&b)<<1
print(a)
