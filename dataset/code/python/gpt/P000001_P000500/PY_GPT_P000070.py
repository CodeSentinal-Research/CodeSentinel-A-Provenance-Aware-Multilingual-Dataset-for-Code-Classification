# problem title : Check Whether Triangle is Valid
# The triangle inequality must hold for all three side pairs.
a, b, c = map(float, input().split())
valid = a + b > c and a + c > b and b + c > a
print("Valid" if valid else "Invalid")
