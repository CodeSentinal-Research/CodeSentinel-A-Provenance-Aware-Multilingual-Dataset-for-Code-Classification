# problem title : Find Type of Triangle
# Classify by counting equal side lengths.
a, b, c = map(float, input().split())
if a == b == c:
    kind = "Equilateral"
elif a == b or b == c or a == c:
    kind = "Isosceles"
else:
    kind = "Scalene"
print(kind)
