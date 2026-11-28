n = int(input())
s = sum(int(x) for x in str(n * n))
if s == n:
    print("Neon")
else:
    print("Not Neon")
