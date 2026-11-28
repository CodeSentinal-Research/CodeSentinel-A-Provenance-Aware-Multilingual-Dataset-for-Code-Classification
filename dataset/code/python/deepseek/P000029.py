Sure, here is the Python code for finding the greatest common divisor (GCD) of two numbers:

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

try:
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    print("The GCD of", a, "and", b, "is", gcd(a, b))
except ValueError:
    print("Invalid input, please enter valid integers.")

This program uses the Euclidean algorithm to find the GCD of two numbers. It works by repeatedly replacing `a` with `b` and `b` with `a mod b` until `b` is `0`. The remainder of `a / b` is then `a`, and we continue until all factors of `a` have been factored out. This algorithm is efficient because it uses the property that the product of two numbers is equal to the product of their greatest common divisor and least common multiple.