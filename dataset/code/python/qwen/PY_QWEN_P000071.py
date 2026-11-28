a, b, c = map(float, input().split())
if a == b == c:
    print("Equilateral")
elif a == b or b == c or c == a:
    print("Isosceles")
else:
    print("Scalene")
