n = int(input())
s = sum(int(x) for x in str(n))
if n % s == 0:
    print("Harshad")
else:
    print("Not Harshad")
